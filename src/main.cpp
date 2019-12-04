#include "mainwindow.h"
#include "Files.h"
#include <QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
	std::string user_input;
	std::string weeks_path;
	std::string teams_path;
	//temporary variables block

	std::string cur_path = std::filesystem::current_path().string();
	//std::cout << cur_path << "\n";
	std::string iddaa_gui_part = "\\iddaa_gui_new";
	weeks_path = cur_path.substr(0, cur_path.find(iddaa_gui_part));
	teams_path = cur_path.substr(0, cur_path.find(iddaa_gui_part));

    QApplication a(argc, argv);
    MainWindow w;
	weeks_path = weeks_path + "\\iddaa_gui_new\\weeks";
	//w.setSomeText(weeks_path);
	teams_path = teams_path + "\\iddaa_gui_new\\teams";
	//std::cout << weeks_path;

	std::vector<std::filesystem::path> match_files = getFileNames(weeks_path);
	std::vector<std::filesystem::path> team_files = getFileNames(teams_path);

	w.setFilePaths(match_files, team_files);
    w.show();
    return a.exec();
}
