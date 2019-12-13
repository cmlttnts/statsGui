#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include "Bet.h"
class BetWeek {
public:
	BetWeek();
	std::string date;
	std::string title;
	std::filesystem::path week_file_path;
	std::vector<Bet> week_bets;
};

std::vector<BetWeek> getAllBetWeeks(const std::vector<std::filesystem::path>&);
std::pair<BetWeek, bool> getBetWeekFromFile(const std::filesystem::path&);