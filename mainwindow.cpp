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
		//TODO : Format how to compare two teams stats
		ui->mainTextArea->append("BULUNDU");
	}

}
