#include "Bet.h"
#include <sstream>
Bet::Bet() : date(""), home_team(""), away_team(""), bet_type(""), odd(1.0), success(false)
{
}

Bet betFromLineData(const BetWeek& week, const std::string& line) {
	Bet bet;
	bet.date = week.date;
	std::istringstream line_stream(line);
	std::getline(line_stream, bet.home_team, ' ');
	std::getline(line_stream, bet.away_team, ' ');
	std::getline(line_stream, bet.bet_type, ' ');

	std::string buffer;
	std::getline(line_stream, buffer, ' ');
	bet.odd = std::stod(buffer);
	std::getline(line_stream, buffer, ' ');
	if (!buffer.compare("y"))
		bet.success = true;
	else
		bet.success = false;
	return bet;
}