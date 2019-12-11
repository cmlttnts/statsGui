#pragma once
#include <filesystem>
#include <string>
#include <vector>
#include <iostream>

std::vector<std::filesystem::path> getFileNames(std::string dir_path);
std::vector<std::vector<std::string>> getTeamNames(const std::vector<std::filesystem::path>&);
std::vector<std::string> _getTeamsFromFile(const std::string&);