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
	final_result(MatchResult::DRAW),
	picked_team_result(TeamsResult::TEAM_DRAW)
{
}


#include <windows.h>

void Match::prettyPresentString() {

	team_names = home_name + "-" + away_name + " : ";
	match_score = "1Y: " + std::to_string(home_first_half_goals) + "-";
	match_score += std::to_string(away_first_half_goals) + " / ";
	match_score += "2Y: " + std::to_string(home_second_half_goals) + "-";
	match_score += std::to_string(away_second_half_goals) + " = MS: ";
	match_score += std::to_string(home_total_goals) + "-";
	match_score += std::to_string(away_total_goals);
	match_score += " (" + std::to_string(static_cast<int>(first_half_result)) + "/" + std::to_string(static_cast<int>(final_result)) + ")";
	
	if (corner_info_available) {
		corners = " Kornerler: (" + std::to_string(home_fh_corners) + "-" + std::to_string(away_fh_corners);
		corners += "/" + std::to_string(home_sh_corners) + "-" + std::to_string(away_sh_corners) + " = ";
		corners += std::to_string(home_total_corners) + "-" + std::to_string(away_total_corners) + ")";
		corners += "Toplam: " + std::to_string(home_total_corners + away_total_corners);
	}
	//if comment exists for that match add new line for pretty printing
	if (comment.compare("")) {
		comment = "\n" + comment;
	}
}










