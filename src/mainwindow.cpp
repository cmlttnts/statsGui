#include "mainwindow.h"
#include "ParseTeam.h"
#include "ParseBet.h"
#include "MyAlgortihms.h"
#include <qdebug.h>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSomeText(const std::string& text) {
	sometext = QString::fromStdString(text);
}

void MainWindow::setFilePaths(const std::vector<std::filesystem::path>& files1, const std::vector<std::filesystem::path>& files2, const std::vector<std::filesystem::path>& files3) {
	match_files = files1;
	team_files = files2;
	bet_history_files = files3;
	QFont analysis_font("Monospace");
	analysis_font.setStyleHint(QFont::Monospace);

	analysis_font.setPointSize(11);
	ui->teamStatsTextArea->setFont(analysis_font);
	ui->teamStatsTextArea->setLineWrapMode(QTextBrowser::NoWrap);

	analysis_font.setPointSize(12);
	ui->compTextArea->setFont(analysis_font);
	ui->bestTeamsTextArea->setFont(analysis_font);
	ui->betHistoryTextArea->setFont(analysis_font);
	ui->teamListTextArea->setFont(analysis_font);
	//ui->teamStatsTextArea->setLineWrapColumnOrWidth(QTextBrowser::NoWrap);
}


//void MainWindow::on_bestTeamComboBox_activated(const QString &arg1)
//{
//    ui->compTextArea->clear();
//    //ui->compTextArea->append("Hello");
//}

#define ALIGN_MATCH_HISTORY 30
#define ALIGN_COMP 25
#define EMPTY_SPACE_QSTRING(X) QString("%1").arg(" ", X, ' ')
#define EMPTY_SPACE_COUNT 12

void MainWindow::on_teamAnalysisButton_clicked()
{

	//first clear the area
	ui->teamStatsTextArea->clear();
	if (!ui->teamAnalysisLineEdit->text().isEmpty()) {
		QString input_str = ui->teamAnalysisLineEdit->text();
		std::pair<Team, bool> team_info = searchFilesForTeam(match_files, input_str.toStdString(),LEAGUE_SEARCH_OPTION::BOTH);
		if (team_info.second) {
			ui->teamStatsTextArea->append("Takım Bulunamadı, Takim Listesindeki isimlerden birini seçiniz!!!");
		}
		else {
			std::sort(team_info.first.matches.begin(), team_info.first.matches.end(), compareByDate);
			unsigned int i = 1;
			QString pretty_str;
			for (const auto& item : team_info.first.matches) {
				if(item.picked_team_result == TeamsResult::TEAM_WIN)
					ui->teamStatsTextArea->setTextColor(Qt::GlobalColor::darkGreen);
				else if(item.picked_team_result == TeamsResult::TEAM_LOSS)
					ui->teamStatsTextArea->setTextColor(Qt::GlobalColor::red);
				else
					ui->teamStatsTextArea->setTextColor(Qt::GlobalColor::black);

				ui->teamStatsTextArea->append(QString("%1").arg(QString::fromStdString(item.date), ALIGN_MATCH_HISTORY, ' '));
				pretty_str = QString("%1").arg(QString::fromStdString(std::to_string(i) + "-)" + item.team_names), -ALIGN_MATCH_HISTORY, ' ');
				pretty_str += QString(" %1\n").arg(QString::fromStdString(item.match_score), ALIGN_MATCH_HISTORY, ' ');
				pretty_str += QString(" %1").arg(QString::fromStdString(item.corners), 2*ALIGN_MATCH_HISTORY+7, ' ');
				pretty_str += QString::fromStdString(item.comment);
				ui->teamStatsTextArea->append(pretty_str);
				i++;
			}

			ui->teamStatsTextArea->setTextColor(Qt::GlobalColor::black);

			pretty_str = "\n"+ EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONUÇLARI İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_wins).arg(team_info.first.num_of_draws).arg(team_info.first.num_of_losses);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI SONUÇLARI İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_first_half_wins).arg(team_info.first.num_of_first_half_draws).arg(team_info.first.num_of_first_half_losses);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İKİNCİ YARI SONUÇLARI İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_second_half_wins).arg(team_info.first.num_of_second_half_draws).arg(team_info.first.num_of_second_half_losses);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONU GOL İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_goals_rec / double(team_info.first.num_of_matches));
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI GOL İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_first_half_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_first_half_goals_rec / double(team_info.first.num_of_matches));
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İKİNCİ YARI GOL İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_second_half_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_second_half_goals_rec / double(team_info.first.num_of_matches));
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONU ALT ÜST İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("2.5 ÜST / 3.5 ÜST / TOPLAM MAÇ = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_above_2_5_matches).arg(team_info.first.num_of_matches - team_info.first.num_of_below_3_5_matches).arg(team_info.first.num_of_matches);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI ALT ÜST İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("1.5 ÜST / 0.5 ALT / TOPLAM MAÇ = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_above_1_5_half_matches).arg(team_info.first.num_of_below_0_5_half_matches).arg(team_info.first.num_of_matches);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("KG VAR İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("KG OLAN/GOL YEMEDİ/GOL ATAMADI/TOPLAM = (%1 / %2 / %3 / %4 )\n").arg(team_info.first.num_of_kg_var_matches).arg(team_info.first.num_of_clean_sheets).arg(team_info.first.num_of_scoreless).arg(team_info.first.num_of_matches);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("SÜRPRİZ ORANLI SONUÇ( 1/X, 2/X, 1/2, 2/1)");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Geriden Geldiği / Önden Geriye Düştüğü  = (%1 / %2 )\n").arg(team_info.first.num_of_comebacks).arg(team_info.first.num_of_gobacks);
			ui->teamStatsTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("KORNER İSTATİSTİKLERİ");
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Korner Bilgili Maç Sayısı = %1 \n").arg(team_info.first.num_of_corner_info_match);
			ui->teamStatsTextArea->append(pretty_str);
			
			pretty_str = QString("1Y Ortalama :  Attı / Yedi / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_first_half_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_first_half_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_first_half_corners+ team_info.first.num_of_first_half_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("2Y Ortalama:  Attı / Yedi / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_second_half_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_second_half_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_second_half_corners+ team_info.first.num_of_second_half_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->teamStatsTextArea->append(pretty_str);
			pretty_str = QString("Maç Ortalama :  Attı / Yedi / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_corners + team_info.first.num_of_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->teamStatsTextArea->append(pretty_str);

		}
	}
	else
		ui->teamStatsTextArea->append("HATA: Bir Takım ismi girin!!!");
    //then show team info
}

void MainWindow::on_teamAnalysisTabWidget_currentChanged(int index)
{
    //Clear text area
    //ui->teamStatsTextArea->clear();
	index++;
}

void MainWindow::on_rootTabWidget_currentChanged(int index)
{
    //ui->teamStatsTextArea->clear();

	// if tab is team name list tab, list the teams
	if (index == 3) {
		if (!team_names_done) {
			team_names = getTeamNames(team_files);
			team_names_done = true;
			listTeamNames();
		}
	}
	else if (index == 4) {
		// if we already parsed betWeeks, don't do it again
		if (!betWeeks_available) {
			betWeeks = getAllBetWeeks(bet_history_files);
			std::sort(betWeeks.begin(), betWeeks.end(), compBetWeekDate);
			for (const auto& betWeek : betWeeks) {
				// add each betWeeks title to combobox to select
				ui->betWeekComboBox->addItem(QString::fromStdString(betWeek.title));
			}
			//  Add another option to select all weeks to see overall score
			ui->betWeekComboBox->addItem("HEPSİ");
			//it is availabe now, don't add again
			betWeeks_available = true;
		}

	}
	//ui->compTextArea->append(sometext);
	index++;

}


#define TEAM_NAME_ALIGN 14

void MainWindow::listTeamNames() {
		{
			QString title = QString(" %1| %2| %3| %4| %5| %6|").arg("TÜRKİYE", -TEAM_NAME_ALIGN, ' ').arg("ALMANYA", -TEAM_NAME_ALIGN, ' ').arg("İNGİLTERE", -TEAM_NAME_ALIGN, ' ').arg("İTALYA", -TEAM_NAME_ALIGN, ' ').arg("İSPANYA", -TEAM_NAME_ALIGN, ' ').arg("ŞAMP.LİGİ", -TEAM_NAME_ALIGN, ' ');
			ui->teamListTextArea->append(title);
		}
		QString str("");
		for (size_t i = 0; i < 20; i++) {
			str = "";
			for (const auto& league : team_names) {
				if (i > league.size() - 1)
					str += EMPTY_SPACE_QSTRING(TEAM_NAME_ALIGN + 1);
				else {
					str += QString(" %1").arg(QString::fromStdString(league[i]), -TEAM_NAME_ALIGN, ' ');
				}
				str += "|";
			}

			ui->teamListTextArea->append(str);
		}
}

//void MainWindow::on_leagueComboBox_activated(const QString &arg1)
//{
//    ui->mainTextArea->clear();
//    //This is where we show league analysis
//}

//void MainWindow::on_compTwoComboBox_activated(int index)
//{
//    //Karşılaştırma için lig opsiyonu
//	//std::tuple<std::string, std::string, COMPARE_TWO_OPTIONS, LEAGUE_SEARCH_OPTION> two_teams = 
//}

#define BEST_TEAMS_TOP_N 15

void MainWindow::on_bestTeamComboBox_activated(int index)
{
	if (index != best_team_prev_index) {
		ui->bestTeamsTextArea->clear();

		if (!best_team_search_done) {
			teams = getAllTeamsStats(match_files);
			best_team_search_done = true;
		}
		switch (index)
		{
		case 0:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::BEST_RESULTS);
			ui->bestTeamsTextArea->append("EN ÇOK MAÇ KAZANANLAR");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_wins) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 1:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::WORST_RESULTS);
			ui->bestTeamsTextArea->append("EN ÇOK MAÇ KAYBEDENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_losses) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 2:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_SCORED);
			ui->bestTeamsTextArea->append("MAÇ BAŞI EN ÇOK GOL ATANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 3:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_SCORED);
			ui->bestTeamsTextArea->append("MAÇ BAŞI EN AZ GOL ATANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 4:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_RECEIVED);
			ui->bestTeamsTextArea->append("MAÇ BAŞI EN ÇOK GOL YİYENLER");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals_rec / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 5:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_RECEIVED);
			ui->bestTeamsTextArea->append("MAÇ BAŞI EN AZ GOL YİYENLER");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals_rec / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 6:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_IN_MATCHES);
			ui->bestTeamsTextArea->append("MAÇLARINDA ORTALAMA EN ÇOK GOL OLANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = (team.num_of_goals + team.num_of_goals_rec) / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 7:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_IN_MATCHES);
			ui->bestTeamsTextArea->append("MAÇLARINDA ORTALAMA EN AZ GOL OLANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = (team.num_of_goals + team.num_of_goals_rec) / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 8:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::COMEBACKS);
			ui->bestTeamsTextArea->append("EN ÇOK GERİDEN GELENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_comebacks) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			sortForBestOption(teams, BEST_TEAM_OPTIONS::GOBACKS);
			ui->bestTeamsTextArea->append("\nEN ÇOK ÖNDEYKEN GERİYE DÜŞENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_gobacks) + " / " + QString::number(team.num_of_matches);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 9:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::TOTAL_CORNERS);
			ui->bestTeamsTextArea->append("MAÇLARINDA EN ÇOK KORNER OLANLAR");
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners + team.num_of_corners_rec) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->bestTeamsTextArea->append(str );
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			sortForBestOption(teams, BEST_TEAM_OPTIONS::CORNERS_TAKEN);
			ui->bestTeamsTextArea->append("\nEN ÇOK KORNER ATANLAR");
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			ui->bestTeamsTextArea->append("\nEN AZ KORNER ATANLAR");
			std::reverse(teams.begin(), teams.end());
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			ui->bestTeamsTextArea->append("\nEN ÇOK KORNER YİYENLER");
			sortForBestOption(teams, BEST_TEAM_OPTIONS::CORNERS_RECEIVED);
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners_rec) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->bestTeamsTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		default:
			break;
		}
	}
	best_team_prev_index = index;
}
//
//void MainWindow::on_leagueComboBox_activated(int index)
//{
//    //yine string olanlı yerine bunu seç
//}

void MainWindow::on_compareButton_clicked()
{
	ui->compTextArea->clear();
    //Comparison button
	LEAGUE_SEARCH_OPTION the_opt = LEAGUE_SEARCH_OPTION::BOTH;
	switch (ui->compTwoComboBox->currentIndex())
	{
	case 0:
		the_opt = LEAGUE_SEARCH_OPTION::ONLY_LEAGUES;
		break;
	case 1:
		the_opt = LEAGUE_SEARCH_OPTION::ONLY_CL;
		break;
	case 2:
		the_opt = LEAGUE_SEARCH_OPTION::BOTH;
		break;
	default:
		break;
	}
	std::pair<Team, bool> team1_info = searchFilesForTeam(match_files, ui->homeTeamLineEdit->text().toStdString(), the_opt);
	std::pair<Team, bool> team2_info = searchFilesForTeam(match_files, ui->awayTeamLineEdit->text().toStdString(), the_opt);
	//if any of the team not found in search, print error msg
	if (team1_info.second || team2_info.second)
		ui->compTextArea->append("Takımlardan en az biri yanlış!");
	else {
		//TEAM NAMES FIRST
		QString frmt_str1 = QString("%1").arg(QString::fromStdString(team1_info.first.name), ALIGN_COMP, ' ');
		frmt_str1 += QString("%1").arg("|", ALIGN_COMP, ' ');
		frmt_str1 += QString("%1").arg(QString::fromStdString(team2_info.first.name), ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1);
		QString frmt_str2;

		// MATCH WINS LOSSES
		frmt_str1 = QString("%1").arg("MAÇ SONUÇLARI", 2 * ALIGN_COMP+7, ' ');
		ui->compTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_wins), QString::number(team1_info.first.num_of_draws), QString::number(team1_info.first.num_of_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2*ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_wins), QString::number(team2_info.first.num_of_draws), QString::number(team2_info.first.num_of_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2*ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		// HOME AWAY PERFORMANCE
		frmt_str1 = QString("%1").arg("EV vs DEP PERFORMANSI", 2 * ALIGN_COMP + 11, ' ');
		ui->compTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT -5 );
		frmt_str1 += QString("Evde (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_home_wins), QString::number(team1_info.first.num_of_home_draws), QString::number(team1_info.first.num_of_home_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-6);
		frmt_str2 += QString("Depte (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_away_wins), QString::number(team2_info.first.num_of_away_draws), QString::number(team2_info.first.num_of_away_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		// FIRST HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İLK YARI SONUÇLARI", 2 * ALIGN_COMP + 9, ' ');
		ui->compTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_first_half_wins), QString::number(team1_info.first.num_of_first_half_draws), QString::number(team1_info.first.num_of_first_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_first_half_wins), QString::number(team2_info.first.num_of_first_half_draws), QString::number(team2_info.first.num_of_first_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		// SECOND HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İKİNCİ YARI SONUÇLARI", 2 * ALIGN_COMP +9, ' ');
		ui->compTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_second_half_wins), QString::number(team1_info.first.num_of_second_half_draws), QString::number(team1_info.first.num_of_second_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_second_half_wins), QString::number(team2_info.first.num_of_second_half_draws), QString::number(team2_info.first.num_of_second_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);
		
		// GOALS SCORED AND RECEIVED
		frmt_str1 = QString("%1").arg("ATILAN YENİLEN GOLLER", 2 * ALIGN_COMP+11, ' ');
		ui->compTextArea->append(frmt_str1);
		double team1_avr = team1_info.first.num_of_goals / double(team1_info.first.num_of_matches);
		double team2_avr = team2_info.first.num_of_goals / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str1 += QString("Attığı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str2 += QString("Attığı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_goals_rec / double(team1_info.first.num_of_matches);
		team2_avr = team2_info.first.num_of_goals_rec / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-9);
		frmt_str1 += QString("Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 8);
		frmt_str2 += QString("Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str1 += QString("Evde Attı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str2 += QString("Depte Attı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals_rec / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals_rec / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str1 += QString("Evde Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Depte Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		// OVER UNDER STATS
		frmt_str1 = QString("%1").arg("ALT ÜST İSTATİSTİKLERİ", 2 * ALIGN_COMP +10, ' ');
		ui->compTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_2_5_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_matches - team1_info.first.num_of_below_3_5_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_matches - team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_1_5_half_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		frmt_str2 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_1_5_half_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_below_0_5_half_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		frmt_str2 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_below_0_5_half_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		// CORNER STATS
		frmt_str1 = QString("%1").arg("KORNER İSTATİSTİKLERİ", 2 * ALIGN_COMP + 10, ' ');
		ui->compTextArea->append(frmt_str1);
		team1_avr = (team1_info.first.num_of_corners + team1_info.first.num_of_corners_rec)/ double(team1_info.first.num_of_corner_info_match);
		team2_avr = (team2_info.first.num_of_corners + team2_info.first.num_of_corners_rec ) / double(team2_info.first.num_of_corner_info_match);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = (team1_info.first.num_of_corners) / double(team1_info.first.num_of_corner_info_match);
		team2_avr = (team2_info.first.num_of_corners) / double(team2_info.first.num_of_corner_info_match);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->compTextArea->append(frmt_str1 + frmt_str2);
	}

}


void MainWindow::on_teamAnalysisLineEdit_returnPressed()
{
	on_teamAnalysisButton_clicked();
}

void MainWindow::on_betHistoryButton_clicked()
{
    //geçmiş bahisler dosyalarında arama yap ve ekrana ver
		//first clear the area
	ui->betHistoryTextArea->clear();
	if (!ui->teamAnalysisLineEdit->text().isEmpty()) {
		QString input_str = ui->teamAnalysisLineEdit->text();
		//ui->betHistoryTextArea->append(QString::fromStdString(bet_history_files[0].string()));
		std::pair<Team, bool> team_info = searchBetFilesForTeam(bet_history_files, input_str.toStdString());
		if (team_info.second) {
			ui->betHistoryTextArea->append("Takım Bulunamadı, Takim Listesindeki isimlerden birini seçiniz!!!");
		}
		else {
			unsigned int i = 1;
			std::string prev_date ="";
			std::sort(team_info.first.bets.begin(), team_info.first.bets.end(), compBetDate);
			for (const auto& bet : team_info.first.bets) {
				if(bet.result == BetResult::WIN)
					ui->betHistoryTextArea->setTextColor(Qt::GlobalColor::darkGreen);
				else if (bet.result == BetResult::LOSS)
					ui->betHistoryTextArea->setTextColor(Qt::GlobalColor::darkRed);
				else
					ui->betHistoryTextArea->setTextColor(Qt::GlobalColor::black);

				if (prev_date.compare(bet.date))
					ui->betHistoryTextArea->append(QString::fromStdString(bet.date));
				ui->betHistoryTextArea->append(QString::number(i)+ ")" + QString::fromStdString(bet.home_team + " " + bet.away_team + " " + bet.bet_type) + " "+  QString::number(bet.odd) + QString::fromStdString(bet.score));
				i++;
				prev_date = bet.date;
			}
		}
	}
	ui->betHistoryTextArea->setTextColor(Qt::GlobalColor::black);

}

void MainWindow::on_betWeekComboBox_activated(int index){
    // Bet Weeks info shown here
	ui->betWeekBetsTextArea->clear();
	ui->betWeekStatsTextArea->clear();

	// if all weeks chosen, show all bets, index of "HEPSİ" is last index
	if (index == betWeeks.size()) {
		std::vector<Bet> all_bets;
		for (const auto& betweek : betWeeks) {
			all_bets.insert(all_bets.end(), betweek.week_bets.begin(), betweek.week_bets.end());
		}

		showBetsAndStats(all_bets, ui->betWeekBetsTextArea, ui->betWeekStatsTextArea);
	}
	else { // we chose a specific week

		showBetsAndStats(betWeeks[index].week_bets, ui->betWeekBetsTextArea, ui->betWeekStatsTextArea);
	}
}

void MainWindow::on_dateSearchButton_clicked()
{
	ui->betWeekBetsTextArea->clear();
	ui->betWeekStatsTextArea->clear();
	// TODO: validate date inputs, if empty take it as no start or end point, meaning show from the beginning or end
	if (betWeeks_available) {
		{
			std::vector<Bet> temp_bets;
			BetWeek temp_start_betweek;
			BetWeek temp_end_betweek;

			temp_start_betweek.date = (ui->startDateLineEdit->text()).toStdString();
			temp_end_betweek.date = (ui->endDateLineEdit->text()).toStdString();

			for (const auto& betweek : betWeeks) {
				//if betweek is between start and end dates, get the bets
				if (compBetWeekDate(temp_start_betweek, betweek) && compBetWeekDate(betweek, temp_end_betweek))
					temp_bets.insert(temp_bets.end(), betweek.week_bets.begin(), betweek.week_bets.end());
			}
			showBetsAndStats(temp_bets, ui->betWeekBetsTextArea, ui->betWeekStatsTextArea);
		}

		//TODO: do this with another button or tab
		std::vector<std::string> bet_types;
		for (const auto& betweek : betWeeks) {
			for (const auto& bet : betweek.week_bets) {
				// don't include bet type that already in the vector
				if (std::find(bet_types.begin(), bet_types.end(), bet.bet_type) == bet_types.end())
					bet_types.push_back(bet.bet_type);
			}
		}
		std::sort(bet_types.begin(), bet_types.end());
		for (const auto& bet_type : bet_types) {
			ui->betWeekStatsTextArea->append(QString::fromStdString(bet_type));
		}
	}
}

void MainWindow::on_prevBetsTabInner_currentChanged(int index)
{
    //Date Search 0, Week Search 1
}


void MainWindow::showBetsAndStats(std::vector<Bet>& bets, QTextBrowser* bets_text_area, QTextBrowser* stats_text_area) {

	unsigned int num_of_finished_bets = 0;
	unsigned int num_of_won_bets = 0;

	double total_winning_odds = 0.0;

	for (const auto& bet : bets) {
		if (bet.result == BetResult::WIN) {
			bets_text_area->setTextColor(Qt::darkGreen);
			num_of_finished_bets++;
			total_winning_odds += bet.odd;
			num_of_won_bets++;
		}
		else if (bet.result == BetResult::LOSS) {
			bets_text_area->setTextColor(Qt::darkRed);
			num_of_finished_bets++;
		}
		else
			bets_text_area->setTextColor(Qt::black);
		bets_text_area->append(QString::fromStdString(bet.home_team + " " + bet.away_team + " " + bet.bet_type + " ") + QString::number(bet.odd) + " " + QString::fromStdString(bet.score));
	}

	stats_text_area->append("Sonuçlanan Bahis Sayısı = " + QString::number(num_of_finished_bets));
	stats_text_area->append("Kazanan Bahis Sayısı = " + QString::number(num_of_won_bets));
	stats_text_area->append("Tutan Oranların Toplamı = " + QString::number(total_winning_odds));
	stats_text_area->append("Kazanç ( x Birim Bahis) = " + QString::number(total_winning_odds - num_of_finished_bets));

}