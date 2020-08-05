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
#define MAIN_Select
#endif

#ifndef FUNC_Select
#define FUNC_Select

#include "utils.h"
#include "InsertSort.cpp"

template <typename T>
T ModifiedPartition(T p, T r, typename T::value_type x) {
	bool x_found = false;
	T l = r - 1;
	T i = p;
	for (T j = p; j != l; j++) {
		if (!x_found && *j == x) {
			std::swap(*j, *l);
			x_found = true;
		}
		if (*j <= x) {
			std::swap(*i, *j);
			i++;
		}
	}
	std::swap(*i, *l);
	return i;
}

template <typename T>
T Median(T p, T r) {
	InsertSort<T>(p, r);
	return p + (r - p - 1) / 2;
}

template <typename T>
T Select(T p, T r, size_t i) {
	if (p == r - 1)
		return p;
	std::vector<typename T::value_type> m;
	for (T i = p; i < r; i += 5) {
		T val;
		if (i + 5 <= r)
			val = Median(i, i + 5);
		else
			val = Median(i, r);
		m.push_back(*val);
	}
	T pos = Select(m.begin(), m.end(), (m.size() - 1) / 2);
	T q = ModifiedPartition(p, r, *pos);
	size_t k = q - p;
	if (i == k)
		return q;
	else if (i < k)
		return Select<T>(p, q, i);
	else
		return Select<T>(q + 1, r, i - k - 1);
}

template <typename T>
T Select(std::vector<T> A, size_t i) {
	return *Select(A.begin(), A.end(), i);
}
#endif

#ifdef MAIN_Select

#include "RandomizedSelect.cpp"

int main(int argc, char *argv[]) {
	std::vector<int> a;
	const size_t n = get_argv(argc, argv, 1, 10);
	const size_t compute = get_argv(argc, argv, 2, 7);
	random_integers(a, 0, n - 1, n);

	std::random_device rd;
    std::uniform_int_distribution<int> d(0, n - 1);
	size_t i = d(rd);
	std::vector<int> b(a);

	int ans1, ans2;

	output_integers(a);
	std::cout << i << std::endl;
	if (compute >> 0 & 1) {
		ans1 = RandomizedSelect(a, i);
		std::cout << ans1 << std::endl;
	}
	if (compute >> 1 & 1) {
		ans2 = Select(b, i);
		std::cout << ans2 << std::endl;
		if (compute >> 0 & 1)
			std::cout << std::boolalpha << (ans1 == ans2) << std::endl;
	}
	return 0;
}
#endif

