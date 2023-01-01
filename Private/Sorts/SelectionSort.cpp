
#include "Sorts/Sorts.h"

void SelectionSort(vector<int>& array)
{
	auto size = array.size();

	int index;

	for (int i = 0; i < size; ++i)
	{
		index = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[j] < array[index])
				index = j;
		}
		if (index != i)
			Swap<int>(array[i], array[index]);
	}
}