#pragma once
#include <string>

enum class BetResult {
	WIN,
	LOSS,
	OTHER
};

class Bet {
public:
	Bet();
	std::string date;
	std::string home_team;
	std::string away_team;
	std::string bet_type;
	double odd;
	BetResult result;
	std::string score;
};



Bet betFromLineData(const std::string&, const std::string&);