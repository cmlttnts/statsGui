#include "Files.h"
#include <string>
#include <fstream>

//return all the file paths
std::vector<std::filesystem::path> getFileNames(std::string dir_path) {
	std::vector<std::filesystem::path> file_names;
	for (const auto& file : std::filesystem::directory_iterator(dir_path)) {
		//std::cout << file.path() << "\n";
		file_names.push_back(file.path());
	}
	return file_names;
}

std::vector<std::vector<std::string>> getTeamNames(const std::vector<std::filesystem::path>& file_paths) {
	std::vector<std::string> tr_teams;
	std::vector<std::string> eng_teams;
	std::vector<std::string> ger_teams;
	std::vector<std::string> ita_teams;
	std::vector<std::string> sp_teams;
	std::vector<std::string> cl_teams;
	for (const auto& file_path : file_paths) {
		//get team names from /teams directory
		std::string file_path_str = file_path.string();
		if (file_path_str.find("cl_teams") != std::string::npos)
			cl_teams = _getTeamsFromFile(file_path_str);
		else if (file_path_str.find("tr_teams") != std::string::npos)
			tr_teams = _getTeamsFromFile(file_path_str);
		else if (file_path_str.find("ger_teams") != std::string::npos)
			ger_teams = _getTeamsFromFile(file_path_str);
		else if (file_path_str.find("eng_teams") != std::string::npos)
			eng_teams = _getTeamsFromFile(file_path_str);
		else if (file_path_str.find("ita_teams") != std::string::npos)
			ita_teams = _getTeamsFromFile(file_path_str);
		else if (file_path_str.find("sp_teams") != std::string::npos)
			sp_teams = _getTeamsFromFile(file_path_str);
	}

	//Now lets order them in alphabetical order
	std::sort(cl_teams.begin(), cl_teams.end());
	std::sort(tr_teams.begin(), tr_teams.end());
	std::sort(ger_teams.begin(), ger_teams.end());
	std::sort(eng_teams.begin(), eng_teams.end());
	std::sort(ita_teams.begin(), ita_teams.end());
	std::sort(sp_teams.begin(), sp_teams.end());
	std::vector<std::vector<std::string>> team_names;
	team_names.push_back(tr_teams);
	team_names.push_back(ger_teams);
	team_names.push_back(eng_teams);
	team_names.push_back(ita_teams);
	team_names.push_back(sp_teams);
	team_names.push_back(cl_teams);
	return team_names;
}


std::vector<std::string> _getTeamsFromFile(const std::string& path) {
	std::ifstream file(path);
	std::vector<std::string> temp;
	std::string line;
	if (file.is_open()) {
		while (getline(file, line)) {
			temp.push_back(line);
		}
	}
	else
		std::cout << "File Cannot Be Opened\n";
	file.close();
	return temp;
}