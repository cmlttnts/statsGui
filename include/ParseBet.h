#pragma once
#include <utility>
#include "Team.h"
#include <filesystem>
#include <vector>
std::pair<Team, bool> searchBetFilesForTeam(const std::vector<std::filesystem::path>&, const std::string&);
bool searchOneBetFile(const std::filesystem::path&, Team&);
std::pair<std::vector<Bet>, bool> getAllTheBetsFromFile(std::filesystem::path);
