#pragma once
#include"stack.h"

class CExpressionHandler
{
public:
	CExpressionHandler();
	bool IsDigital(TCHAR * p);
	~CExpressionHandler();
private:
	CStack<double> m_NumStack;
	CStack<TCHAR> m_OpeStack;
	TCHAR *m_pCurrent;
	CString m_strExpression;

	//私有成员函数
	void PushNumber();
	//void MoveToNextOperator();
	BOOL IsHigherThanStackTop(TCHAR * p);
	int GetPriority(TCHAR c);
	void PushStack();
	double Compute(double dX, double dY, TCHAR cOpt);
	void PushOperator(TCHAR * p);
	//void MoveToNextCharacter();
	void Execute();
	void InitialPoint();


public:
	void SetExpression(CString strExpression);
	CString GetResult();
	void Run();
private:
	bool ComparePriority(TCHAR * cp, TCHAR * p);
};

