
#include "Sorts/Sorts.h"

using std::vector;

void MergeSortImplement(vector<int>& array, int start, int end);
void Merging(vector<int>& array, int start, int mid, int end);

void MergeSort(vector<int>& array)
{
	MergeSortImplement(array, 0, array.size() - 1);
}

void MergeSortImplement(vector<int>& array, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSortImplement(array, start, mid);
		MergeSortImplement(array, mid + 1, end);
		Merging(array, start, mid, end);
	}
} 

void Merging(vector<int>& array, int start, int mid, int end)
{
	int n1 = mid - start + 1;
	int n2 = end - mid;

	vector<int> a1(n1);
	vector<int> a2(n2);
	
	for (int i = 0; i < n1; ++i)
		a1[i] = array[start + i];

	for (int i = 0; i < n2; ++i)
		a2[i] = array[mid + i + 1];

	int i = 0;
	int j = 0;
	int k = start;

	while (k < end && i < n1 && j < n2)
	{
		if (a1[i] <= a2[j])
			array[k++] = a1[i++];
		else
			array[k++] = a2[j++];
	}

	while (i < n1)
		array[k++] = a1[i++];
	while (j < n2)
		array[k++] = a2[j++];
}