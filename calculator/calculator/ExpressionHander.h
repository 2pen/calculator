

#pragma once
#include "Cstack.h"
#include<math.h>
class CExpressionHander
{
public:
	CExpressionHander();
	~CExpressionHander();
private:
	bool IsDigital(TCHAR c);//识别数字
	int IsHighPriority(TCHAR first, TCHAR last);//识别运算符优先级
	int Getpriority(TCHAR c);//获得优先级
public:
	double GetResult (double dX, double dY, TCHAR cOpt);
private:
	

private:
	Cstack<double>m_NumStack;
	Cstack<TCHAR> m_OptStack;
	CString m_strExpresssion;
	CString m_strResult;
	TCHAR  *m_pCurrent;//指向当前字符指针
    void PushOperator(TCHAR c);//压栈运算符和左右括号
    void PushNum(double dX);//压栈数字
    void StoreNumber();//数字转化为指针字符，压入栈中
    void MoveToNextOperator();//判断是否为运算符，移动指针到下一个
    void MoveToNextNumber();//判断知否为数字，移动到指针到下一个
    void PreParedOperationData(double &dX, double &dY, TCHAR &cOpt);//初始化数据
    void ScanExpression();//执行运算步骤
    bool IsNotEnd();//判断运算是否结束
    bool bError;

public:
	void SetExpression(CString expression);
	void Run();
	CString GetValue();
};
