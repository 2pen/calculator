

#pragma once
#include "Cstack.h"
#include<math.h>
class CExpressionHander
{
public:
	CExpressionHander();
	~CExpressionHander();
private:
	bool IsDigital(TCHAR c);//ʶ������
	int IsHighPriority(TCHAR first, TCHAR last);//ʶ����������ȼ�
	int Getpriority(TCHAR c);//������ȼ�
public:
	double GetResult (double dX, double dY, TCHAR cOpt);
private:
	

private:
	Cstack<double>m_NumStack;
	Cstack<TCHAR> m_OptStack;
	CString m_strExpresssion;
	CString m_strResult;
	TCHAR  *m_pCurrent;//ָ��ǰ�ַ�ָ��
    void PushOperator(TCHAR c);//ѹջ���������������
    void PushNum(double dX);//ѹջ����
    void StoreNumber();//����ת��Ϊָ���ַ���ѹ��ջ��
    void MoveToNextOperator();//�ж��Ƿ�Ϊ��������ƶ�ָ�뵽��һ��
    void MoveToNextNumber();//�ж�֪��Ϊ���֣��ƶ���ָ�뵽��һ��
    void PreParedOperationData(double &dX, double &dY, TCHAR &cOpt);//��ʼ������
    void ScanExpression();//ִ�����㲽��
    bool IsNotEnd();//�ж������Ƿ����
    bool bError;

public:
	void SetExpression(CString expression);
	void Run();
	CString GetValue();
};
