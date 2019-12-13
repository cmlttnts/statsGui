#include "BetWeek.h"
#include <fstream>
#include "Bet.h"
#include "ParseBet.h"
BetWeek::BetWeek(): date(""), title("")
{

}

std::vector<BetWeek> getAllBetWeeks(const std::vector<std::filesystem::path>& paths) {
	std::vector<BetWeek> betweeks;
	std::pair<BetWeek, bool> bet_week_and_failure;
	for (const auto& path : paths) {
		bet_week_and_failure = getBetWeekFromFile(path);
		if(!bet_week_and_failure.second)
			betweeks.push_back(bet_week_and_failure.first);
	}
	return betweeks;
}

std::pair<BetWeek, bool> getBetWeekFromFile(const std::filesystem::path& path){

	std::pair<BetWeek, bool> bet_week_and_failure;
	auto bets_and_failure = getAllTheBetsFromFile(path);
	if (!bets_and_failure.second)
		bet_week_and_failure.first.week_bets = bets_and_failure.first;

	std::ifstream file(path);
	bet_week_and_failure.first.week_file_path = path;
	bet_week_and_failure.second = true;
	if (file.is_open()) {
		std::string line;
		bool first_line = true;
		bool sec_line = false;
		while (std::getline(file, line)) {
			if (first_line) {
				bet_week_and_failure.first.date = line;
				sec_line = true;
				first_line = false;
			}
			else if (sec_line) {
				bet_week_and_failure.first.title = line;
				sec_line = false;
				// betWeek found, failure set to false
				bet_week_and_failure.second = false;
				break;
			}
		}
	}
	else // file didn't open, failure happened
		bet_week_and_failure.second = true;
	return bet_week_and_failure;
}

