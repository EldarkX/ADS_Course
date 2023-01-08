#pragma once

#include<ADS.h>

template<class T>
struct Node
{
	T		data;
	Node	*next;
};

//Circled single linked list
template<class T>
class LinkedList
{
public:
	LinkedList()
	{
		sentinel = new Node<T>;
		sentinel->data = 0;
		sentinel->next = sentinel;
	}
	//O(1)
	void Insert(T value)
	{
		Node<T> *NewNode = new Node<T>();
		NewNode->data = value;
		NewNode->next = sentinel->next;
		sentinel->next = NewNode;
	}
	//O(n)
	void Remove(Node<T>* node)
	{
		if (!IsEmpty() && node)
		{
			Node<T>* tmp = sentinel;
			while (tmp->next != sentinel && tmp->next != node)
			{
				tmp = tmp->next;
			}
			if (tmp->next != sentinel)
			{
				tmp->next = node->next;
				delete node;
			}
		}
	}
	//O(n)
	void Remove(T value)
	{
		Remove(Search(value));
	}
	//O(n)
	Node<T>* Search(T value)
	{
		sentinel->data = value;
		Node<T> *tmp = sentinel->next;
		while (tmp->data != value)
		{
			tmp = tmp->next;
		}
		return tmp == sentinel ? nullptr : tmp;
	}
	Node<T>* Head() const
	{
		if (!IsEmpty())
			return sentinel->next;
		return nullptr;
	}
	bool IsEmpty() const
	{
		return sentinel->next == sentinel;
	}
	void Print()
	{
		Node<T> *tmp = sentinel->next;
		while (tmp != sentinel)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	~LinkedList()
	{
		delete sentinel;
	}
private:
	Node<T>*	sentinel = nullptr;
};

void TestLinkedList();