
#include "ADS.h"
#include <DataStructures/Deque.h>

void TestDeque()
{
	const size_t size = 8;

	Deque<int, size> dq;

	cout << "Fulfill by pushing: ";
	for (size_t i = 0; i < size; ++i)
	{
		dq.Push(i);
	}
	while (!dq.IsEmpty())
	{
		cout << dq.Pop() << " ";
	}
	cout << endl;

	cout << "Fulfill by enqueue: ";
	for (size_t i = 0; i < size; ++i)
	{
		dq.Enqueue(i);
	}
	while (!dq.IsEmpty())
	{
		cout << dq.Dequeue() << " ";
	}
	cout << endl;

	//check overflow
	int overflowSize = size + 1;
	for (size_t i = 0; i < overflowSize; ++i)
	{
		dq.Push(i);
	}
	dq.Enqueue(size - 1); //check overflow with enqueue

	//check looping
	for (size_t i = 0; i < size - 1; ++i)
	{
		dq.Dequeue();
	}
	dq.Push(0);
	dq.Pop();
	dq.Enqueue(0);
	for (size_t i = 1; i < size; ++i)
	{
		if (i % 2 == 0)
		{
			dq.Enqueue(i);
		}
		else
		{
			dq.Push(i);
		}
	}
	cout << "Looped sequence: ";
	while (!dq.IsEmpty())
	{
		cout << dq.Pop() << " ";
	}
	cout << endl;
}
