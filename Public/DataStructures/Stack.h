#pragma once

template<class T, int Size>
class Stack
{
public:
	void	Push(T value)
	{
		if (ptr < Size - 1) //overflow protection
		{
			++ptr;
			data[ptr] = value;
		}
	}

	T		Pop()
	{
		if (!IsEmpty()) //underflow protection
		{
			return data[ptr--];
		}
		return 0;
	}

	bool	IsEmpty() const;

private:
	int				ptr = -1;
	T				data[Size];
};

template<class T, int Size>
bool Stack<T, Size>::IsEmpty() const
{
	return ptr < 0;
}

void TestStack();