#include "mainwindow.h"
#include "Files.h"
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
	std::string user_input;
	std::string weeks_path;
	std::string teams_path;
	std::string bet_history_path;
	//temporary variables block

	std::string cur_path = std::filesystem::current_path().string();
	//std::cout << cur_path << "\n";
	std::string statsGui_gui_part = "\\statsGui_gui_new";
	weeks_path = cur_path.substr(0, cur_path.find(statsGui_gui_part));
	teams_path = cur_path.substr(0, cur_path.find(statsGui_gui_part));
	bet_history_path = cur_path.substr(0, cur_path.find(statsGui_gui_part));
    QApplication a(argc, argv);
    MainWindow w;
	weeks_path = weeks_path + "\\statsGui_gui_new\\weeks";
	//w.setSomeText(weeks_path);
	teams_path = teams_path + "\\statsGui_gui_new\\teams";
	bet_history_path = bet_history_path + "\\statsGui_gui_new\\bet_history";
	//std::cout << weeks_path;

	std::vector<std::filesystem::path> match_files = getFileNames(weeks_path);
	std::vector<std::filesystem::path> team_files = getFileNames(teams_path);
	std::vector<std::filesystem::path> bet_hist_files = getFileNames(bet_history_path);


	w.setFilePaths(match_files, team_files, bet_hist_files);
    w.show();
    return a.exec();
}
