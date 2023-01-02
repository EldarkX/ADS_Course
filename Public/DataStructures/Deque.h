#pragma once

template <class T, int Size>
class Deque
{
public:
	void	Enqueue(T value)
	{
		if (!IsFull()) //overflow protection
		{
			data[tail] = value;
			tail = (tail == Size - 1) ? 0 : (tail + 1);
			isEmpty = false;
		}
	}

	T		Dequeue()
	{
		T value = 0;
		if (!IsEmpty()) //underflow protection
		{
			value = data[head];
			head = (head == Size - 1) ? 0 : (head + 1);
			isEmpty = head == tail;
		}
		return value;
	}

	void	Push(T value)
	{
		Enqueue(value);
	}

	T		Pop()
	{
		T value = 0;
		if (!IsEmpty()) //underflow protection
		{
			value = data[tail];
			tail = (tail == 0) ? Size - 1 : tail - 1;
			isEmpty = head == tail;
		}
		return value;
	}

	bool	IsEmpty() const;
	bool	IsFull() const;

private:
	T		data[Size];
	size_t	tail = 0;
	size_t	head = 0;
	bool	isEmpty = true;
};

template<class T, int Size>
bool Deque<T, Size>::IsEmpty() const
{
	return isEmpty;
}

template<class T, int Size>
bool Deque<T, Size>::IsFull() const
{
	return head == tail && !isEmpty;
}

void TestDeque();