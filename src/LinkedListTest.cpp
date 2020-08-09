//
//  algorithm - some algorithms in "Introduction to Algorithms", third edition
//  Copyright (C) 2020  lxylxy123456
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

#include "LinkedList.hpp"
#include "utils.hpp"

#include <cassert>

using namespace algorithms;

template <typename T>
int test(std::string t) {
	std::cout << t << std::endl;
	LinkedListBase<int>* S = new T;
	Data<int>* nil = nullptr;
	if (t == "LinkedList_prime")
		nil = S->ListSearch(0);
	for (int i = 0; i < 100; i++)
		S->ListInsert(i);
	for (int i = 0; i < 102; i++) {
		Data<int>* ptr = S->ListSearch(i);
		assert((ptr == nil) == (i >= 100));
		if (i % 2 == 0 && i < 100)
			S->ListDelete(ptr);
	}
	for (int i = 0; i < 102; i++) {
		Data<int>* ptr = S->ListSearch(i);
		assert((ptr == nil) == (i % 2 == 0 || i >= 100));
	}
	return 0;
}

int main(int argc, char *argv[]) {
	test<LinkedList<int>>("LinkedList");
	test<LinkedList_prime<int>>("LinkedList_prime");
	return 0;
}
