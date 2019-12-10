#pragma once
#include "Match.h"
#include "Team.h"
#include <vector>
#include "Interface.h"

void sortForBestOption(std::vector<Team>&, BEST_TEAM_OPTIONS);

bool compareByDate(const Match&, const Match&);
bool compareByWins(const Team& team1, const Team& team2);
bool compareByLosses(const Team& team1, const Team& team2);
bool compareByFHWins(const Team& team1, const Team& team2);
bool compareByFHLosses(const Team& team1, const Team& team2);
bool compareBySHWins(const Team& team1, const Team& team2);
bool compareBySHLosses(const Team& team1, const Team& team2);
bool compareByTotalCorners(const Team& team1, const Team& team2);
bool compareByCornersTaken(const Team& team1, const Team& team2);
bool compareByCornersRec(const Team& team1, const Team& team2);


bool compareByMostGoalsScored(const Team& team1, const Team& team2);
bool compareByMostGoalsRec(const Team& team1, const Team& team2);
bool compareByMostGoalsFH(const Team& team1, const Team& team2);
bool compareByMostGoalsSH(const Team& team1, const Team& team2);

bool compareByMostGoalsInMatch(const Team& team1, const Team& team2);


bool compareByComebacksAndGobacks(const Team& team1, const Team& team2);
bool compareByComebacks(const Team& team1, const Team& team2);
bool compareByGobacks(const Team& team1, const Team& team2);
void rankTeamsByOption(std::vector<Team>&, BEST_TEAM_OPTIONS);