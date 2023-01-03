#pragma once

#include<ADS.h>

template<class T>
struct Node
{
	T		data;
	Node	*next;
};

template<class T>
class LinkedList
{
public:
	void Insert(T value)
	{
		Node<T> *NewNode = new Node<T>();
		NewNode->data = value;
		NewNode->next = head;
		head = NewNode;
	}
	void Remove(Node<T>* node)
	{
		if (node && head)
		{
			Node<T>* tmp = head;
			if (node == head)
			{	
				head = head->next;
				delete tmp;
			}
			else
			{
				while (tmp->next && tmp->next != node)
					tmp = tmp->next;
				tmp->next = node->next;
				delete node;
			}
		}
	}
	void Remove(T value)
	{
		Remove(Search(value));
	}
	Node<T>* Search(T value)
	{
		Node<T> *tmp = head;
		while (tmp)
		{
			if (tmp->data == value)
				return tmp;
			tmp = tmp->next;
		}
		return nullptr;
	}
	Node<T>* Head() const
	{
		return head;
	}
	bool IsEmpty() const
	{
		return head == nullptr;
	}
	void Print()
	{
		Node<T> *tmp = head;
		while (tmp)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}

private:
	Node<T>*	head = nullptr;
};

void TestLinkedList();