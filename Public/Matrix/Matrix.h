#pragma once

#include "ADS.h"

template<class C, int m, int n>
class Matrix
{

public:
	Matrix();
	Matrix(const vector<vector<C>> &v);
	Matrix(const Matrix &mx);

	Matrix &operator=(const Matrix &mx);

	C operator()(int r, int c) const { return data[r][c]; }
	C &operator()(int r, int c) { return data[r][c]; }

	int Rows() const { return m; }
	int Cols() const { return n; }

	void Print() const;

private:
	C data[m][n == 0 ? 1 : n];
};

template<class C, int m1, int n1, int m2, int n2>
Matrix<C, m1, n2> operator*(const Matrix<C, m1, n1>& mx1, const Matrix<C, m2, n2>& mx2)
{
	static_assert(n1 == m2);

	Matrix<C, m1, n2> resultMatrix;
	C sum = 0;

	for (int r = 0; r < m1; ++r)
	{
		for (int c = 0; c < n2; ++c)
		{
			sum = 0;
			for (int r2 = 0; r2 < m2; ++r2)
				sum += mx1(r, r2) * mx2(r2, c);
			resultMatrix(r, c) = sum;
		}
	}
	return resultMatrix;
}

template<class C, int m1, int n1, int m2, int n2>
Matrix<C, m1, n2> operator+(const Matrix<C, m1, n1>& mx1, const Matrix<C, m2, n2>& mx2)
{
	Matrix<C, m1, n2> resultMatrix;
	
	for (int r = 0; r < m1; ++r)
	{
		for (int c = 0; c < n2; ++c)
		{
			resultMatrix(r, c) = mx1(r, c) + mx2(r, c);
		}
	}
	return resultMatrix;
}

template<class C, int m, int n>
Matrix<C, m, n>::Matrix()
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = 0;
}

template<class C, int m, int n>
Matrix<C, m, n>::Matrix(const vector<vector<C>>& v)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = v[i][j];
}

template<class C, int m, int n>
Matrix<C, m, n>::Matrix(const Matrix& mx)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = mx(i, j);
}

template<class C, int m, int n>
Matrix<C, m, n>& Matrix<C, m, n>::operator=(const Matrix<C, m, n>& mx)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			data[i][j] = mx(i, j);
	return *this;
}

template<class C, int m, int n>
void Matrix<C, m, n>::Print() const
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << setw(4) << data[i][j] << " ";
		cout << endl;
	}
}

template<class C, int n, int n1, int n2>
Matrix<C, n, n> &&MultiplyRecursiveGetSubmatrix(const Matrix<C, n1, n1>& A, int i, int j, const Matrix<C, n2, n2> B, int k, int l)
{
	Matrix<C, n, n> result;
	if (n <= 1)
		result(0, 0) = A(i, j) * B(k, l);
	else
	{
		const int newSize = n / 2;
		Matrix<C, newSize, newSize> C1, C2, C3, C4;
		C1 = MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, i, j, B, k, l) + MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, i, newSize + 1, B, newSize + 1, l);
		C2 = MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, i, j, B, k, newSize + 1) + MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, i, newSize + 1, B, newSize + 1, newSize + 1);
		C3 = MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, newSize + 1, j, B, k, l) + MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, newSize + 1, newSize + 1, B, newSize + 1, l);
		C4 = MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, newSize + 1, j, B, k, newSize + 1) + MultiplyRecursiveGetSubmatrix<C, newSize, n1, n2>(A, newSize + 1, newSize + 1, B, newSize + 1, newSize + 1);	
		
		for (int r = 0; r < newSize; ++r)
		{
			for (int c = 0; c < newSize; ++c)
				result(r, c) = C1(r, c);
		}
		for (int r = 0; r < newSize; ++r)
		{
			for (int c = newSize + 1; c < n; ++c)
				result(r, c) = C2(r, c - newSize - 1);
		}
		for (int r = newSize + 1; r < n; ++r)
		{
			for (int c = 0; c < newSize; ++c)
				result(r, c) = C3(r - newSize - 1, c);
		}
		for (int r = newSize + 1; r < n; ++r)
		{
			for (int c = newSize + 1; c < n; ++c)
				result(r, c) = C4(r - newSize - 1, c - newSize - 1);
		}
	}
	return std::move(result);
}

template<class C, int n>
Matrix<C, n, n>&& MultiplyRecursive(const Matrix<C, n, n>& mx1, const Matrix<C, n, n>& mx2)
{
	return std::move(MultiplyRecursiveGetSubmatrix<C, n, n, n>(mx1, 0, 0, mx2, 0, 0));
}