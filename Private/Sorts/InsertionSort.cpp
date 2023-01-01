
#include "Sorts/Sorts.h"
#include "Utils/Utils.h"

using std::vector;

void InserionSort(std::vector<int>& array)
{
	auto size = array.size();

	int j;

	for (int i = 0; i < size; ++i)
	{
		j = i;
		while (j > 0 && array[j] < array[j - 1])
		{
			Swap<int>(array[j], array[j - 1]);
			--j;
		}
	}
	}