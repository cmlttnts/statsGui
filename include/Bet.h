#pragma once
#include <string>

enum class BetResult {
	WIN,
	LOSS,
	OTHER
};

//enum class BetType {
//	MS_1,
//	MS_X,
//	MS_2,
//
//	MS_1_VE_UST_2_5,
//	MS_1_VE_UST_1_5,
//	
//	MS_2_VE_UST_2_5,
//	MS_2_VE_UST_1_5,
//
//	MS_X_VE_UST_2_5,
//	MS_X_VE_ALT_2_5,
//
//	KORNER_1Y_UST_4_5,
//	KORNER_1Y_UST_5_5,
//
//	KORNER_MS_UST_8_5,
//	KORNER_1Y_UST_9_5,
//
//	UST_2_5,
//	ALT_2_5,
//	UST_3_5,
//	ALT_3_5,
//
//	BTTS,
//
//};






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