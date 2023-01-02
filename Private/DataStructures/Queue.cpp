
#include <DataStructures/Queue.h>
#include <ADS.h>

// TEST
void TestQueue()
{
	const size_t size = 8;

	Queue<int, size> q;

	int overflowSize = size + 1;
	for (size_t i = 0; i < overflowSize; ++i) //check overflow
	{
		q.Enqueue(i);
	}

	while (!q.IsEmpty())
	{
		cout << q.Dequeue() << " ";
	}
	cout << endl;

	for (size_t i = 0; i < size; ++i)
	{
		q.Enqueue(i);
	}

	for (size_t i = 0; i < size / 2; ++i)
	{
		q.Dequeue();
	}

	for (size_t i = 0; i < size / 2; ++i)
	{
		q.Enqueue(i);
	}

	while (!q.IsEmpty())
	{
		cout << q.Dequeue() << " ";
	}
	cout << endl;

	q.Dequeue(); // check underflow
}