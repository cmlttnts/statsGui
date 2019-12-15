#pragma once
#include <vector>


// given a list with size N, generate combinations with size M
template <class T>
void getCombinations(const std::vector<T>& list, int M, std::vector<std::vector<T>>& all_combinations, std::vector<T>& combination) {
	// error
	if (M > list.size())
		return;
	if (M == 0)
		all_combinations.push_back(combination);
	else {

		for (int i = 0; i < list.size(); i++) {
			combination.push_back(list[i]);
			getCombinations(std::vector<T>(list.begin() + i+1, list.end()), M - 1, all_combinations, combination);
			combination.pop_back();
		}
	}

}