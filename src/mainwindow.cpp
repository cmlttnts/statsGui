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
}


void MainWindow::on_bestTeamComboBox_activated(const QString &arg1)
{
    ui->mainTextArea->clear();
    //ui->mainTextArea->append("Hello");
}

void MainWindow::on_teamAnalysisButton_clicked()
{
    //first clear the area
    ui->mainTextArea->clear();
	if (!ui->teamAnalysisLineEdit->text().isEmpty()) {
		std::pair<Team, bool> team_info = searchFilesForTeam(match_files, ui->teamAnalysisLineEdit->text().toStdString(),LEAGUE_SEARCH_OPTION::BOTH);
		if (team_info.second) {
			ui->mainTextArea->append("Takım Bulunamadı, Takim Listesindeki isimlerden birini seçiniz!!!");
		}
		else {
			std::sort(team_info.first.matches.begin(), team_info.first.matches.end(), sortMatchesByDate);
			unsigned int i = 1;
			for (const auto& item : team_info.first.matches) {
				if(item.picked_team_result == TeamsResult::TEAM_WIN)
					ui->mainTextArea->setTextColor(Qt::GlobalColor::darkGreen);
				else if(item.picked_team_result == TeamsResult::TEAM_LOSS)
					ui->mainTextArea->setTextColor(Qt::GlobalColor::red);
				else
					ui->mainTextArea->setTextColor(Qt::GlobalColor::black);
				ui->mainTextArea->append(QString::fromStdString(std::to_string(i)+ "-)" +item.pretty_str));
				i++;
			}

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
}

void MainWindow::on_rootTabWidget_currentChanged(int index)
{
    ui->mainTextArea->clear();
	//ui->mainTextArea->append(sometext);
}

void MainWindow::on_leagueComboBox_activated(const QString &arg1)
{
    ui->mainTextArea->clear();
    //This is where we show league analysis
}

void MainWindow::on_compTwoComboBox_activated(int index)
{
    //Karşılaştırma için lig opsiyonu
	//std::tuple<std::string, std::string, COMPARE_TWO_OPTIONS, LEAGUE_SEARCH_OPTION> two_teams = 
}

void MainWindow::on_bestTeamComboBox_activated(int index)
{
    //STring olanlı yerine bunu kullan daha rahat
}

void MainWindow::on_leagueComboBox_activated(int index)
{
    //yine string olanlı yerine bunu seç
}
#define ALIGN_COMP 50
#define EMPTY_SPACE_QSTRING(X) QString("%1").arg(" ", X, ' ')
#define EMPTY_SPACE_COUNT 25
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
		frmt_str1 = QString("%1").arg("MAÇ SONUÇLARI", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_wins), QString::number(team1_info.first.num_of_draws), QString::number(team1_info.first.num_of_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2*ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_wins), QString::number(team2_info.first.num_of_draws), QString::number(team2_info.first.num_of_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2*ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// HOME AWAY PERFORMANCE
		frmt_str1 = QString("%1").arg("EV vs DEP PERFORMANSI", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT -5 );
		frmt_str1 += QString("Evde (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_home_wins), QString::number(team1_info.first.num_of_home_draws), QString::number(team1_info.first.num_of_home_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-6);
		frmt_str2 += QString("Depte (G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_away_wins), QString::number(team2_info.first.num_of_away_draws), QString::number(team2_info.first.num_of_away_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// FIRST HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İLK YARI SONUÇLARI", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_first_half_wins), QString::number(team1_info.first.num_of_first_half_draws), QString::number(team1_info.first.num_of_first_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_first_half_wins), QString::number(team2_info.first.num_of_first_half_draws), QString::number(team2_info.first.num_of_first_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// SECOND HALF PERFORMANCE
		frmt_str1 = QString("%1").arg("İKİNCİ YARI SONUÇLARI", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str1 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team1_info.first.num_of_second_half_wins), QString::number(team1_info.first.num_of_second_half_draws), QString::number(team1_info.first.num_of_second_half_losses));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT);
		frmt_str2 += QString("(G /B /M )= (%1 / %2 / %3)").arg(QString::number(team2_info.first.num_of_second_half_wins), QString::number(team2_info.first.num_of_second_half_draws), QString::number(team2_info.first.num_of_second_half_losses));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);
		
		// GOALS SCORED AND RECEIVED
		frmt_str1 = QString("%1").arg("ATILAN YENİLEN GOLLER", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		double team1_avr = team1_info.first.num_of_goals / double(team1_info.first.num_of_matches);
		double team2_avr = team2_info.first.num_of_goals / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str1 += QString("Attığı Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str2 += QString("Attığı Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_goals_rec / double(team1_info.first.num_of_matches);
		team2_avr = team2_info.first.num_of_goals_rec / double(team2_info.first.num_of_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT-15);
		frmt_str1 += QString("Yediği Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 17);
		frmt_str2 += QString("Yediği Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 15);
		frmt_str1 += QString("Evde Attığı Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 19);
		frmt_str2 += QString("Depte Attığı Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = team1_info.first.num_of_home_goals_rec / double(team1_info.first.num_of_home_matches);
		team2_avr = team2_info.first.num_of_away_goals_rec / double(team2_info.first.num_of_away_matches);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 15);
		frmt_str1 += QString("Evde Yediği Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 20);
		frmt_str2 += QString("Depte Yediği Ort. / Maç Sayısı : %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// OVER UNDER STATS
		frmt_str1 = QString("%1").arg("ALT ÜST İSTATİSTİKLERİ", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_2_5_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("2.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_matches - team1_info.first.num_of_below_3_5_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("3.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_matches - team2_info.first.num_of_above_2_5_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_above_1_5_half_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		frmt_str2 += QString("İlk Yarı 1.5 ÜST / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_above_1_5_half_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team1_info.first.num_of_below_0_5_half_matches), QString::number(team1_info.first.num_of_matches));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 12);
		frmt_str2 += QString("İlk Yarı 0.5 ALT / Maç Sayısı: %1 / %2").arg(QString::number(team2_info.first.num_of_below_0_5_half_matches), QString::number(team2_info.first.num_of_matches));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		// CORNER STATS
		frmt_str1 = QString("%1").arg("KORNER İSTATİSTİKLERİ", 2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1);
		team1_avr = (team1_info.first.num_of_corners + team1_info.first.num_of_corners_rec)/ double(team1_info.first.num_of_corner_info_match);
		team2_avr = (team2_info.first.num_of_corners + team2_info.first.num_of_corners_rec ) / double(team2_info.first.num_of_corner_info_match);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Maçlarında Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);

		team1_avr = (team1_info.first.num_of_corners) / double(team1_info.first.num_of_corner_info_match);
		team2_avr = (team2_info.first.num_of_corners) / double(team2_info.first.num_of_corner_info_match);
		frmt_str1 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str1 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team1_avr), QString::number(team1_info.first.num_of_corner_info_match));
		frmt_str1 = QString("%1").arg(frmt_str1, -2 * ALIGN_COMP, ' ');
		frmt_str2 = EMPTY_SPACE_QSTRING(EMPTY_SPACE_COUNT - 10);
		frmt_str2 += QString("Attıkları Ort. / Maç Sayısı: %1 / %2").arg(QString::number(team2_avr), QString::number(team2_info.first.num_of_corner_info_match));
		frmt_str2 = QString("%1").arg(frmt_str2, -2 * ALIGN_COMP, ' ');
		ui->mainTextArea->append(frmt_str1 + frmt_str2);
	}

}
