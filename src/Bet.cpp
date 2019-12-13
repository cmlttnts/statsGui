#include "Bet.h"
#include <sstream>
Bet::Bet() : date(""), home_team(""), away_team(""), bet_type(""), odd(1.0), result(BetResult::OTHER)
{
}

Bet betFromLineData(const std::string& date, const std::string& line) {
	Bet bet;
	bet.date = date;
	std::istringstream line_stream(line);
	std::getline(line_stream, bet.home_team, ' ');
	std::getline(line_stream, bet.away_team, ' ');
	std::getline(line_stream, bet.bet_type, ' ');

	std::string buffer;
	std::getline(line_stream, buffer, ' ');
	bet.odd = std::stod(buffer);
	std::getline(line_stream, buffer, ' ');
	if (!buffer.compare("y"))
		bet.result = BetResult::WIN;
	else if (!buffer.compare("n"))
		bet.result = BetResult::LOSS;
	else
		bet.result = BetResult::OTHER;
	std::getline(line_stream, bet.score, ' ');
	return bet;
}