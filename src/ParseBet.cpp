#include "ParseBet.h"
#include <fstream>
#include "Bet.h"
#include "BetWeek.h"

std::pair<Team, bool> searchBetFilesForTeam(const std::vector<std::filesystem::path>& file_paths, const std::string& team_name) {

	std::pair<Team, bool> team_info;
	team_info.first = Team(team_name);
	//boolean failure of finding that team in the search of files
	team_info.second = true;
	// Read files to modify team's properties
	for (const auto& path : file_paths) {
		//if we find at least 1 bet we say it is success
		team_info.second = searchOneBetFile(path, team_info.first) && team_info.second;
	}
	return team_info;
}

//return true if failed to find team in the file
bool searchOneBetFile(const std::filesystem::path& file_path, Team& team) {
	std::ifstream file(file_path);
	bool failure = true;
	if (file.is_open()) {
		
		std::string line;
		Bet temp_bet;
		BetWeek temp_bet_week;
		bool first_line = true;
		bool sec_line = false;
		while (std::getline(file, line)) {
			if (first_line) {
				temp_bet_week.date = line;
				sec_line = true;
				first_line = false;
			}
			else if (sec_line) {
				temp_bet_week.title = line;
				sec_line = false;
			}
			else {
				temp_bet = betFromLineData(temp_bet_week.date, line);
				//  compare names with team's name
				if (!team.name.compare(temp_bet.home_team) || !team.name.compare(temp_bet.away_team)) {
					team.bets.push_back(temp_bet);
					failure = false;
				}
			}

		}
		return failure;

	}
	else
		return failure;
}

std::pair<std::vector<Bet>, bool> getAllTheBetsFromFile(std::filesystem::path path) {
	std::ifstream file(path);
	bool failure = true;
	std::pair<std::vector<Bet>, bool> week_bets_and_failure;
	week_bets_and_failure.second = true; // set failure true at start

	if (file.is_open()) {
		std::string line;
		Bet temp_bet;
		BetWeek temp_bet_week;
		bool first_line = true;
		bool sec_line = false;
		while (std::getline(file, line)) {
			if (first_line) {
				temp_bet_week.date = line;
				sec_line = true;
				first_line = false;
			}
			else if (sec_line) {
				temp_bet_week.title = line;
				sec_line = false;
			}
			else {
				temp_bet = betFromLineData(temp_bet_week.date, line);
				//
				week_bets_and_failure.first.push_back(temp_bet);
				week_bets_and_failure.second = false; // we found at least one bet, that makes it success

			}

		}

	}
	return week_bets_and_failure;
}