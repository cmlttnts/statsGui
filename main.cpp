#include "mainwindow.h"
#include "Files.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	std::string user_input;
	std::string weeks_path;
	std::string teams_path;
	//temporary variables block

		std::string cur_path = std::filesystem::current_path().string();
		//std::cout << cur_path << "\n";
		//std::string iddaa_cpp_part = "\\iddaa_cpp";
		//weeks_path = cur_path.substr(0, cur_path.find(iddaa_cpp_part));
		//teams_path = cur_path.substr(0, cur_path.find(iddaa_cpp_part));

	weeks_path = cur_path + "\\weeks";
	teams_path = cur_path + "\\teams";
	std::vector<std::filesystem::path> match_files = getFileNames(weeks_path);
	std::vector<std::filesystem::path> team_files = getFileNames(teams_path);

    QApplication a(argc, argv);
    MainWindow w;
	w.setFilePaths(match_files, team_files);
    w.show();
    return a.exec();
}
