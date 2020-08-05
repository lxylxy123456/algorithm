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

#include "Huffman.hpp"

#include "utils.h"
#include "printtree.h"
#include "MaxHeap.hpp"

using namespace algorithms;

int main(int argc, char *argv[]) {
	const size_t n = get_argv(argc, argv, 1, 6);
	// prepare data
	std::vector<CNode<char>> C;
	std::vector<size_t> freq_list;
	random_integers<size_t>(freq_list, 1, n, n);
	for (size_t i = 0; i < n; i++)
		C.push_back(CNode<char>('a' + i, freq_list[i]));
	output_integers(C, "\t");
	output_integers(freq_list, "\t");
	std::cout << std::endl;
	// call function
	CNode<char>* B = Huffman(C);
	printTree(CNodeDesc<char>(B));
	return 0;
}
