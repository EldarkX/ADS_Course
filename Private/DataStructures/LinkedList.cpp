
#include<DataStructures/LinkedList.h>

void TestLinkedList()
{
	LinkedList<int> list;

	list.Print();
	list.Search(14);

	for (int i = 0; i < 10; ++i)
		list.Insert(i);

	list.Print();
	list.Remove(4);
	list.Remove(list.Search(3));
	list.Print();

	while (!list.IsEmpty())
	{
		list.Remove(list.Head());
	}
	list.Print();
	list.Remove(list.Head());

	for (int i = 0; i < 3; ++i)
		list.Insert(i);
	list.Print();
	while (!list.IsEmpty())
	{
		list.Remove(list.Head());
	}

	//reverse
	for (int i = 0; i < 6; ++i)
		list.Insert(i);
	list.Reverse();
	list.Print();
	list.Reverse();
	list.Print();
	while (!list.IsEmpty())
	{
		list.Remove(list.Head());
	}
	list.Print();
}

