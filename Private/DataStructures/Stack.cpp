
#include <DataStructures/Stack.h>
#include <ADS.h>

// TEST
void TestStack()
{
	const size_t size = 256;

	Stack<int, size> s;

	size_t overflowSize = size + 1;
	for (size_t i = 0; i < overflowSize; ++i)
	{
		s.Push(i);
	}

	while (!s.IsEmpty())
	{
		cout << s.Pop() << endl;
	}

	s.Pop(); // check underflow
}