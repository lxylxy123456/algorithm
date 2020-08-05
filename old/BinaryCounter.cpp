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
#define MAIN_BinaryCounter
#endif

#ifndef FUNC_BinaryCounter
#define FUNC_BinaryCounter

#include "utils.h"

class BinaryCounter {
	public:
		BinaryCounter(size_t k): A(k) {}
		void Increment() {
			for (std::vector<bool>::iterator i = A.begin(); i != A.end(); i++) {
				*i = !*i;
				if (*i)
					break;
			}
		}
		template <typename T>
		T x() {
			T ans = 0;
			for (auto i = A.rbegin(); i != A.rend(); i++) {
				ans <<= 1;
				*i && ans++;
			}
			return ans;
		}
		std::vector<bool> A;
};
#endif

#ifdef MAIN_BinaryCounter
int main(int argc, char *argv[]) {
	const size_t n = get_argv(argc, argv, 1, 1000);
	const size_t k = get_argv(argc, argv, 2, 10);
	const size_t compute = get_argv(argc, argv, 3, 1);
	BinaryCounter A(k);
	for (size_t i = 0; i < n; i++) {
		A.Increment();
		compute && std::cout << A.x<size_t>() << std::endl;
	}
	std::cout << A.x<size_t>() << std::endl;
	return 0;
}
#endif
