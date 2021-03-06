//  
//  algorithm - some algorithms in "Introduction to Algorithms", third edition
//  Copyright (C) 2018  lxylxy123456
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as
//  published by the Free Software Foundation, either version 3 of the
//  License, or (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  

#ifndef MAIN
#define MAIN
#define MAIN_OnLineMaximum
#endif

#ifndef FUNC_OnLineMaximum
#define FUNC_OnLineMaximum

#include <algorithm>
#include "utils.h"

template <typename T>
size_t OnLineMaximum(std::vector<T> candidates, size_t k) {
	size_t n = candidates.size(); 
	T best_score = candidates[0]; 
	for (size_t i = 0; i < k; i++)
		if (candidates[i] > best_score)
			best_score = candidates[i]; 
	for (size_t i = k; i < n; i++)
		if (candidates[i] > best_score)
			return i; 
	return n - 1; 
}
#endif

#ifdef MAIN_OnLineMaximum
int main(int argc, char *argv[]) {
	size_t n = get_argv(argc, argv, 1, 27); 
	size_t k = get_argv(argc, argv, 2, 10); 
	std::vector<int> c; 
	random_integers(c, 0, n - 1, n); 
	output_integers(c); 
	int ans = OnLineMaximum(c, k); 
	int max = std::max_element(c.begin(), c.end()) - c.begin(); 
	std::cout << ans << '\t' << c[ans] << std::endl; 
	std::cout << max << '\t' << c[max] << std::endl; 
	std::cout << std::boolalpha << (ans == max) << std::endl; 
	return 0; 
}
#endif

