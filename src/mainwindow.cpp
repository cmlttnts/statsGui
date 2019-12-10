#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ParseTeam.h"
#include "MyAlgortihms.h"
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

void MainWindow::setFilePaths(const std::vector<std::filesystem::path>& files1, const std::vector<std::filesystem::path>& files2) {
	match_files = files1;
	team_files = files2;
	QFont analysis_font("Monospace");
	analysis_font.setStyleHint(QFont::Monospace);

	analysis_font.setPointSize(11);
	ui->mainTextArea->setCurrentFont(analysis_font);
}


//void MainWindow::on_bestTeamComboBox_activated(const QString &arg1)
//{
//    ui->mainTextArea->clear();
//    //ui->mainTextArea->append("Hello");
//}

#define ALIGN_MATCH_HISTORY 30
#define ALIGN_COMP 25
#define EMPTY_SPACE_QSTRING(X) QString("%1").arg(" ", X, ' ')
#define EMPTY_SPACE_COUNT 12

void MainWindow::on_teamAnalysisButton_clicked()
{
    //first clear the area
    ui->mainTextArea->clear();
	if (!ui->teamAnalysisLineEdit->text().isEmpty()) {
		QString input_str = ui->teamAnalysisLineEdit->text();
		std::pair<Team, bool> team_info = searchFilesForTeam(match_files, input_str.toStdString(),LEAGUE_SEARCH_OPTION::BOTH);
		if (team_info.second) {
			ui->mainTextArea->append("Takım Bulunamadı, Takim Listesindeki isimlerden birini seçiniz!!!");
		}
		else {
			std::sort(team_info.first.matches.begin(), team_info.first.matches.end(), compareByDate);
			unsigned int i = 1;
			QString pretty_str;
			for (const auto& item : team_info.first.matches) {
				if(item.picked_team_result == TeamsResult::TEAM_WIN)
					ui->mainTextArea->setTextColor(Qt::GlobalColor::darkGreen);
				else if(item.picked_team_result == TeamsResult::TEAM_LOSS)
					ui->mainTextArea->setTextColor(Qt::GlobalColor::red);
				else
					ui->mainTextArea->setTextColor(Qt::GlobalColor::black);

				ui->mainTextArea->append(QString("%1").arg(QString::fromStdString(item.date), ALIGN_MATCH_HISTORY, ' '));
				pretty_str = QString("%1").arg(QString::fromStdString(std::to_string(i) + "-)" + item.team_names), -ALIGN_MATCH_HISTORY, ' ');
				pretty_str += QString(" %1").arg(QString::fromStdString(item.match_score), ALIGN_MATCH_HISTORY, ' ');
				pretty_str += QString(" %1").arg(QString::fromStdString(item.corners), ALIGN_MATCH_HISTORY, ' ');
				pretty_str += QString::fromStdString(item.comment);
				ui->mainTextArea->append(pretty_str);
				i++;
			}

			ui->mainTextArea->setTextColor(Qt::GlobalColor::black);

			pretty_str = "\n"+ EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONUÇLARI İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_wins).arg(team_info.first.num_of_draws).arg(team_info.first.num_of_losses);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI SONUÇLARI İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_first_half_wins).arg(team_info.first.num_of_first_half_draws).arg(team_info.first.num_of_first_half_losses);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İKİNCİ YARI SONUÇLARI İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("G / B / M = (%1 / %2 / %3)\n").arg(team_info.first.num_of_second_half_wins).arg(team_info.first.num_of_second_half_draws).arg(team_info.first.num_of_second_half_losses);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONU GOL İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_goals_rec / double(team_info.first.num_of_matches));
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI GOL İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_first_half_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_first_half_goals_rec / double(team_info.first.num_of_matches));
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İKİNCİ YARI GOL İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Maç başına ortalama ATTI / YEDİ = (%1 / %2 )\n").arg(team_info.first.num_of_second_half_goals / double(team_info.first.num_of_matches)).arg(team_info.first.num_of_second_half_goals_rec / double(team_info.first.num_of_matches));
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("MAÇ SONU ALT ÜST İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("2.5 ÜST / 3.5 ÜST / TOPLAM MAÇ = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_above_2_5_matches).arg(team_info.first.num_of_matches - team_info.first.num_of_below_3_5_matches).arg(team_info.first.num_of_matches);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("İLK YARI ALT ÜST İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("1.5 ÜST / 0.5 ALT / TOPLAM MAÇ = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_above_1_5_half_matches).arg(team_info.first.num_of_below_0_5_half_matches).arg(team_info.first.num_of_matches);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("KG VAR İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("KG OLAN / GOL YEMEDİĞİ / GOL ATAMADIĞI /  TOPLAM MAÇ = (%1 / %2 / %3 / %4 )\n").arg(team_info.first.num_of_kg_var_matches).arg(team_info.first.num_of_clean_sheets).arg(team_info.first.num_of_scoreless).arg(team_info.first.num_of_matches);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("SÜRPRİZ ORANLI SONUÇ( 1/X, 2/X, 1/2, 2/1)");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Geriden Geldiği / Önden Geriye Düştüğü  = (%1 / %2 )\n").arg(team_info.first.num_of_comebacks).arg(team_info.first.num_of_gobacks);
			ui->mainTextArea->append(pretty_str);

			pretty_str = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
			pretty_str += QString("KORNER İSTATİSTİKLERİ");
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Korner Bilgisine Sahip Maç Sayısı = %1 \n").arg(team_info.first.num_of_corner_info_match);
			ui->mainTextArea->append(pretty_str);
			
			pretty_str = QString("1Y Maç Başı Ortalama :  Attıkları / Yedikleri / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_first_half_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_first_half_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_first_half_corners+ team_info.first.num_of_first_half_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("2Y Maç Başı Ortalama:  Attıkları / Yedikleri / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_second_half_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_second_half_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_second_half_corners+ team_info.first.num_of_second_half_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->mainTextArea->append(pretty_str);
			pretty_str = QString("Maç Sonu Ortalama :  Attıkları / Yedikleri / TOPLAM = (%1 / %2 / %3 )\n").arg(team_info.first.num_of_corners / double(team_info.first.num_of_corner_info_match)).arg(team_info.first.num_of_corners_rec / double(team_info.first.num_of_corner_info_match)).arg((team_info.first.num_of_corners + team_info.first.num_of_corners_rec) / double(team_info.first.num_of_corner_info_match));
			ui->mainTextArea->append(pretty_str);

		}
	}
	else
		ui->mainTextArea->append("HATA: Bir Takım ismi girin!!!");
    //then show team info
}

void MainWindow::on_teamAnalysisTabWidget_currentChanged(int index)
{
    //Clear text area
    ui->mainTextArea->clear();
	index++;
}

void MainWindow::on_rootTabWidget_currentChanged(int index)
{
    ui->mainTextArea->clear();

	// if tab is team name list tab, list the teams
	if (index == 3) {
		if (!team_names_done) {
			team_names = getTeamNames(team_files);
			team_names_done = true;
		}
		listTeamNames();
	}
	//ui->mainTextArea->append(sometext);
	index++;

}


#define TEAM_NAME_ALIGN 14

void MainWindow::listTeamNames() {
	

	{
		QString title = QString(" %1| %2| %3| %4| %5| %6|").arg("TÜRKİYE", -TEAM_NAME_ALIGN, ' ').arg("ALMANYA", -TEAM_NAME_ALIGN, ' ').arg("İNGİLTERE", -TEAM_NAME_ALIGN, ' ').arg("İTALYA", -TEAM_NAME_ALIGN, ' ').arg("İSPANYA", -TEAM_NAME_ALIGN, ' ').arg("ŞAMP.LİGİ", -TEAM_NAME_ALIGN, ' ');
		ui->mainTextArea->append(title);
	}
	QString str("");
	for (size_t i = 0; i < 20; i++) {
		str = "";
		for (const auto& league : team_names) {
			if (i > league.size() - 1)
				str += EMPTY_SPACE_QSTRING(TEAM_NAME_ALIGN+1);
			else {
				str += QString(" %1").arg(QString::fromStdString(league[i]), -TEAM_NAME_ALIGN, ' ');
			}
			str += "|";
		}

		ui->mainTextArea->append(str);
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
		ui->mainTextArea->clear();

		if (!best_team_search_done) {
			teams = getAllTeamsStats(match_files);
			best_team_search_done = true;
		}
		switch (index)
		{
		case 0:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::BEST_RESULTS);
			ui->mainTextArea->append("EN ÇOK MAÇ KAZANANLAR");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_wins) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 1:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::WORST_RESULTS);
			ui->mainTextArea->append("EN ÇOK MAÇ KAYBEDENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_losses) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 2:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_SCORED);
			ui->mainTextArea->append("MAÇ BAŞI EN ÇOK GOL ATANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 3:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_SCORED);
			ui->mainTextArea->append("MAÇ BAŞI EN AZ GOL ATANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 4:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_RECEIVED);
			ui->mainTextArea->append("MAÇ BAŞI EN ÇOK GOL YİYENLER");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals_rec / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 5:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_RECEIVED);
			ui->mainTextArea->append("MAÇ BAŞI EN AZ GOL YİYENLER");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = team.num_of_goals_rec / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 6:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::MOST_GOALS_IN_MATCHES);
			ui->mainTextArea->append("MAÇLARINDA ORTALAMA EN ÇOK GOL OLANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = (team.num_of_goals + team.num_of_goals_rec) / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 7:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::LEAST_GOALS_IN_MATCHES);
			ui->mainTextArea->append("MAÇLARINDA ORTALAMA EN AZ GOL OLANLAR");
			{
				unsigned int i = 1;
				double avrg = 0.0;
				QString str;
				for (const auto& team : teams) {
					avrg = (team.num_of_goals + team.num_of_goals_rec) / double(team.num_of_matches);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 8:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::COMEBACKS);
			ui->mainTextArea->append("EN ÇOK GERİDEN GELENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_comebacks) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			sortForBestOption(teams, BEST_TEAM_OPTIONS::GOBACKS);
			ui->mainTextArea->append("\nEN ÇOK ÖNDEYKEN GERİYE DÜŞENLER");
			{
				unsigned int i = 1;
				QString str;
				for (const auto& team : teams) {
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(team.num_of_gobacks) + " / " + QString::number(team.num_of_matches);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			break;
		case 9:
			sortForBestOption(teams, BEST_TEAM_OPTIONS::TOTAL_CORNERS);
			ui->mainTextArea->append("MAÇLARINDA EN ÇOK KORNER OLANLAR");
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners + team.num_of_corners_rec) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->mainTextArea->append(str );
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			sortForBestOption(teams, BEST_TEAM_OPTIONS::CORNERS_TAKEN);
			ui->mainTextArea->append("\nEN ÇOK KORNER ATANLAR");
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			ui->mainTextArea->append("\nEN AZ KORNER ATANLAR");
			std::reverse(teams.begin(), teams.end());
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->mainTextArea->append(str);
					i++;
					if (i > BEST_TEAMS_TOP_N)
						break;
				}
			}
			ui->mainTextArea->append("\nEN ÇOK KORNER YİYENLER");
			sortForBestOption(teams, BEST_TEAM_OPTIONS::CORNERS_RECEIVED);
			{
				unsigned int i = 1;
				QString str;
				double avrg = 0.0;
				for (const auto& team : teams) {
					avrg = (team.num_of_corners_rec) / double(team.num_of_corner_info_match);
					str = QString::number(i) + "-) " + QString::fromStdString(team.name) + " " + QString::number(avrg) + " / " + QString::number(team.num_of_corner_info_match);
					ui->mainTextArea->append(str);
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
	ui->mainTextArea->clear();
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
		ui->mainTextArea->append("Takımlardan en az biri yanlış!");
	else {
		//TEAM NAMES FIRST
		QString frmt_str1 = QString("%1").arg(QString::fromStdString(team1_info.first.name), ALIGN_COMP, ' ');
		frmt_str1 += QString("%1").arg("|", ALIGN_COMP, ' ');
		frmt_str1 += QString("%1").arg(QString::fromStdString(team2_info.first.name), ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		QString frmt_str2;

		// MATCH WINS LOSSES
		frmt_str1 = QString("%1").arg("MAÇ SONUÇLARI", 2 * ALIGN_COMP+7, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_wins), QString::number(team1_info.first.num_of_draws), QString::number(team1_info.first.num_of_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2*ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_wins), QString::number(team2_info.first.num_of_draws), QString::number(team2_info.first.num_of_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2*ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// HOME AWAY PERFORMANCE
		frmt_str1 = QString("%1").arg("EV vs DEP PERFORMANSI", 2 * ALIGN_COMP + 11, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT -5 );
		frmt_str1 += QString("Evde (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_home_wins), QString::number(team1_info.first.num_of_home_draws), QString::number(team1_info.first.num_of_home_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-6);
		frmt_str2 += QString("Depte (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_away_wins), QString::number(team2_info.first.num_of_away_draws), QString::number(team2_info.first.num_of_away_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// FIRST HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İLK YARI SONUÇLARI", 2 * ALIGN_COMP + 9, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_first_half_wins), QString::number(team1_info.first.num_of_first_half_draws), QString::number(team1_info.first.num_of_first_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_first_half_wins), QString::number(team2_info.first.num_of_first_half_draws), QString::number(team2_info.first.num_of_first_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// SECOND HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İKİNCİ YARI SONUÇLARI", 2 * ALIGN_COMP +9, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_second_half_wins), QString::number(team1_info.first.num_of_second_half_draws), QString::number(team1_info.first.num_of_second_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_second_half_wins), QString::number(team2_info.first.num_of_second_half_draws), QString::number(team2_info.first.num_of_second_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);
		
		// GOALS SCORED AND RECEIVED
		frmt_str1 = QString("%1").arg("ATILAN YENİLEN GOLLER", 2 * ALIGN_COMP+11, ' ');
		ui->mainTextArea->append(frmt_str1);
		double team1_avr = team1_info.first.num_of_goals / double(team1_info.first.num_of_matches);
		double team2_avr = team2_info.first.num_of_goals / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str1 += QString("Attığı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str2 += QString("Attığı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_goals_rec / double(team1_info.first.num_of_matches);
		team2_avr = team2_info.first.num_of_goals_rec / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-9);
		frmt_str1 += QString("Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 8);
		frmt_str2 += QString("Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str1 += QString("Evde Attı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str2 += QString("Depte Attı Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals_rec / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals_rec / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 9);
		frmt_str1 += QString("Evde Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Depte Yedi Ort. / Maç Sayı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//// OVER UNDER STATS
		//frmt_str1 = QString("%1").arg("ALT ÜST İSTATİSTİKLERİ", 2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1);
		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_2_5_matches), QString::number(team1_info.first.num_of_matches));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str2 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_matches - team1_info.first.num_of_below_3_5_matches), QString::number(team1_info.first.num_of_matches));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str2 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_matches - team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_1_5_half_matches), QString::number(team1_info.first.num_of_matches));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		//frmt_str2 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_1_5_half_matches), QString::number(team2_info.first.num_of_matches));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_below_0_5_half_matches), QString::number(team1_info.first.num_of_matches));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		//frmt_str2 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_below_0_5_half_matches), QString::number(team2_info.first.num_of_matches));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//// CORNER STATS
		//frmt_str1 = QString("%1").arg("KORNER İSTATİSTİKLERİ", 2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1);
		//team1_avr = (team1_info.first.num_of_corners + team1_info.first.num_of_corners_rec)/ double(team1_info.first.num_of_corner_info_match);
		//team2_avr = (team2_info.first.num_of_corners + team2_info.first.num_of_corners_rec ) / double(team2_info.first.num_of_corner_info_match);
		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str2 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);

		//team1_avr = (team1_info.first.num_of_corners) / double(team1_info.first.num_of_corner_info_match);
		//team2_avr = (team2_info.first.num_of_corners) / double(team2_info.first.num_of_corner_info_match);
		//frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str1 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		//frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		//frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		//frmt_str2 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		//frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		//ui->mainTextArea->append(frmt_str1 + frmt_str2);
	}

}


void MainWindow::on_teamAnalysisLineEdit_returnPressed()
{
	on_teamAnalysisButton_clicked();
}
