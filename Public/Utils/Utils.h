#pragma once

#include <vector>
#include <iostream>

void GenerateRandomArray(std::vector<int> &array, int min, int max);
bool TestSorts(const std::vector<int>& array);

template <class T>
void PrintVector(T &v)
{
	for (auto iter = v.cbegin(); iter != v.cend(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

template <class T>
void Swap(T& v1, T& v2)
{
	T tmp = v1;
	v1 = v2;
	v2 = tmp;
}
