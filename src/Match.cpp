#include "Match.h"
#include <iostream>
Match::Match()
:pretty_str(""), home_name(""), away_name(""),
comment(""), date(""),
home_first_half_goals(0),
home_second_half_goals(0),
home_total_goals(0),
away_first_half_goals(0),
away_second_half_goals(0),
away_total_goals(0),
first_half_result(MatchResult::DRAW),
second_half_result(MatchResult::DRAW),
final_result(MatchResult::DRAW)
{
}


#include <windows.h>

void Match::prettyPresentString() {

	pretty_str = home_name + "-" + away_name + " : ";
	pretty_str += "1Y: " + std::to_string(home_first_half_goals) + "-";
	pretty_str += std::to_string(away_first_half_goals) + " / ";
	pretty_str += "2Y: " + std::to_string(home_second_half_goals) + "-";
	pretty_str += std::to_string(away_second_half_goals) + " = MS: ";
	pretty_str += std::to_string(home_total_goals) + "-";
	pretty_str += std::to_string(away_total_goals);
	pretty_str += " (" + std::to_string(static_cast<int>(first_half_result)) + "/" + std::to_string(static_cast<int>(final_result)) + ")";
	
	if (corner_info_available) {
		pretty_str += " Corners:(" + std::to_string(home_fh_corners) + "-" + std::to_string(away_fh_corners);
		pretty_str += "/" + std::to_string(home_sh_corners) + "-" + std::to_string(away_sh_corners) + " = ";
		pretty_str += std::to_string(home_total_corners) + "-" + std::to_string(away_total_corners) + ")";
	}
	if (comment.compare("")) {
		pretty_str += "\n" + comment;
	}
}










