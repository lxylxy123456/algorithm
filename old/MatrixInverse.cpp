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
#define MAIN_MatrixInverse
#endif

#ifndef FUNC_MatrixInverse
#define FUNC_MatrixInverse

#include "utils.h"

#include "LUPSolve.cpp"

template <typename T>
Matrix<T> MatrixInverse(Matrix<T>& A) {
	const size_t n = A.rows;
	Matrix<T> LU(A), ans(n, 0), b(n, 1, 0);
	PT pi = LUPDecomposition(LU);
	for (size_t i = 0; i < n; i++) {
		b[i][0] = 1;
		Matrix<T> x = LUPSolve(LU, LU, pi, b);
		ans = ans.concat_h(x);
		b[i][0] = 0;
	}
	return ans;
}
#endif

#ifdef MAIN_MatrixInverse
template <typename T>
void main_T(const size_t n) {
	std::vector<int> int_a, int_b;
	random_integers(int_a, -n, n, n * n);
	std::vector<T> buf_a(n * n), buf_b(n);
	for (size_t i = 0; i < int_a.size(); i++)
		buf_a[i] = int_a[i];
	Matrix<T> A(n, n, buf_a);
	std::cout << A << std::endl;
	Matrix<T> B = MatrixInverse(A);
	std::cout << B << std::endl;
	Matrix<T> C = SquareMatrixMultiply(A, B, (T) 0);
	std::cout << C << std::endl;
}

int main(int argc, char *argv[]) {
	const size_t type = get_argv(argc, argv, 1, 0);
	const size_t n = get_argv(argc, argv, 2, 5);
	if (!type)
		main_T<double>(n);
	else
		main_T<Fraction<int>>(n);
	return 0;
}
#endif

