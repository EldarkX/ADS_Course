
#include "Utils/Utils.h"
#include "Sorts/Sorts.h"
#include <cstdlib>
#include <algorithm>
#include <ctime>

using std::vector;

void GenerateRandomArray(std::vector<int> &array, int min, int max)
{
	srand(static_cast<unsigned int>(time(0))); 

	for (auto &vi : array)
		vi = rand() % (max - min + 1) + min;
}

bool TestSorts(const std::vector<int>& array)
{
	auto array1 = array;
	auto array2 = array;
	auto array3 = array;

	BubbleSort(array1);
	SelectionSort(array2);
	MergeSort(array3);

	for (int i = 0, size = array.size(); i < size; ++i)
	{
		if (array1[i] != array2[i] || array1[i] != array3[i] || array2[i] != array3[i])
			return false;
	}

	return true;
}
