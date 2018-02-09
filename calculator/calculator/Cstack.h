
#pragma once

template<class Type>

class Cstack
{
public:
	Cstack()  
	{
		stack.SetSize(20, 20);
    }
	~Cstack()
	{
}

bool IsEmpty()
	{
		return stack.IsEmpty();
	}

Type Top()
	{

		return stack[0];

    }




	Type  Pop()
{

Type  element = stack.GetAt(0);
		stack.RemoveAt(0);
		return element;
 }  




	void Push(Type element)
	{
     stack.InsertAt(0, element);   //—π»Î’ª∂•£¨∆‰”‡ÀÊ∫Û

    }

private:
	CArray<Type, Type> stack;


};

