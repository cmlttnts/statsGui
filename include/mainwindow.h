#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "Files.h"
#include "Team.h"
#include "ui_mainwindow.h"
#include "BetWeek.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
	QString sometext;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	void setSomeText(const std::string&);
	void setFilePaths(const std::vector<std::filesystem::path>&, const std::vector<std::filesystem::path>&, const std::vector<std::filesystem::path>&);
private slots:
    //void on_bestTeamComboBox_activated(const QString &arg1);

    void on_teamAnalysisButton_clicked();

    void on_teamAnalysisTabWidget_currentChanged(int index);

    void on_rootTabWidget_currentChanged(int index);

    //void on_leagueComboBox_activated(const QString &arg1);

    //void on_compTwoComboBox_activated(int index);

    void on_bestTeamComboBox_activated(int index);

    //void on_leagueComboBox_activated(int index);

    void on_compareButton_clicked();


    void on_teamAnalysisLineEdit_returnPressed();

	void listTeamNames();

    void on_betHistoryButton_clicked();

    void on_betWeekComboBox_activated(int index);

    void on_dateSearchButton_clicked();

    void on_prevBetsTabInner_currentChanged(int index);

	void showBetsAndStats(std::vector<Bet>&, QTextBrowser*, QTextBrowser*);

private:
    Ui::MainWindow *ui;
	std::vector<std::filesystem::path> match_files;
	std::vector<std::filesystem::path> team_files;
	std::vector<std::filesystem::path> bet_history_files;

	std::vector<std::vector<std::string>> team_names;
	bool team_names_done = false;

	std::vector<BetWeek> betWeeks;
	bool betWeeks_available;

	bool teams_listed = false;

	std::vector<Team> teams;
	bool best_team_search_done = false;
	int best_team_prev_index = -1;
};

#endif // MAINWINDOW_H
