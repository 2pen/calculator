#pragma once

template<class T>
class CStack
{
public:
	CStack(){}
	~CStack(){}

	bool IsEmpty()
	{
		return stack.IsEmpty();
	}
	T Top(){
		return stack.GetAt(0);//stack[0];
	}
	T Pop()
	{
		T element = stack.GetAt(0);
		stack.RemoveAt(0);
		return element;
	}

	void Push(T element)
	{
		stack.InsertAt(0, element);
	}

private:
	CArray<T, T>stack;
};