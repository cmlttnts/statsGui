#pragma once
#include <string>
#include "BetWeek.h"

class Bet {
public:
	Bet();
	std::string date;
	std::string home_team;
	std::string away_team;
	std::string bet_type;
	double odd;
	bool success;
};

Bet betFromLineData(const BetWeek&, const std::string&);