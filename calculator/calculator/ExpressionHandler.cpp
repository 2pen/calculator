#include "stdafx.h"
#include "ExpressionHandler.h"


CExpressionHandler::CExpressionHandler()
{
}


CExpressionHandler::~CExpressionHandler()
{
}




bool CExpressionHandler::IsDigital(TCHAR * p)
{
	if ((*p>= _T('0')&& *p <= _T('9'))||
		*p == _T('.'))
		return true;
	else 	return false;
}


void CExpressionHandler::PushNumber()
{ 
	double num = _tstof(m_pCurrent);
	//double numpoint = 0;
	while (IsDigital(m_pCurrent))
	{//_tstof
		m_pCurrent++;
		/*if (*m_pCurrent == _T('.'))
		{
			m_pCurrent++;
			break;
		}*/
	}
	/*while (IsDigital(m_pCurrent))
	{
		numpoint=num
	}
*/
	m_NumStack.Push(num);//×ª³ÉÊý×Ö
}


//void CExpressionHandler::MoveToNextOperator()
//{
//	while (IsDigital(m_pCurrent))
//	{
//		m_pCurrent++;
//	}
//}


BOOL CExpressionHandler::IsHigherThanStackTop(TCHAR * p)
{
	if (m_OpeStack.IsEmpty())
		return 1;//0
	if (*p == _T('('))
		return 1;
	if (*p == _T(')') && m_OpeStack.Top() != _T('('))
		return 0;
	if (m_OpeStack.Top() == _T(')')&&m_OpeStack.Top()==_T('('))
		return 1;
	
	if (GetPriority(*p)>=GetPriority(m_OpeStack.Top()))
	return 0;
	else	return 1;
}


int CExpressionHandler::GetPriority(TCHAR c)
{
	switch (c)
	{
	case _T('c'):
	case _T('s'):
		return -1;
	case _T('^'):
		return 0;
	case _T('¡Á'):
	case _T('¡Â'):
		return 1;
	case _T('+'):
	case _T('-'):
		return 2;
	case _T('='):
		return 3;
	}
}


void CExpressionHandler::PushStack()
{
	double dX;
	TCHAR cOpt=m_OpeStack.Pop();
	if (cOpt == _T('s'))
	{
		dX = m_NumStack.Pop();
		m_NumStack.Push(sin(dX));
		return;
	}
	if (cOpt == _T('c'))
	{
		dX = m_NumStack.Pop();
		m_NumStack.Push(cos(dX));
		return;
	}
	double dY = m_NumStack.Pop();
	dX = m_NumStack.Pop(); 
	
	m_NumStack.Push(Compute(dX, dY, cOpt));
}


double CExpressionHandler::Compute(double dX, double dY, TCHAR cOpt)
{
	switch (cOpt)
	{
	case _T('^'):return pow(dX,(int)dY);
	case _T('¡Á'):return dX*dY;
	case _T('¡Â'):
		if (dY == 0)
		{
			throw 0;
		}
		else return dX / dY;
	case _T('+'):return dX + dY;
	case _T('-'):return dX - dY;
	}
}


void CExpressionHandler::PushOperator(TCHAR * p)
{
	if (*p == _T(')') && m_OpeStack.Top() == _T('('))
		m_OpeStack.Pop();
	else
	m_OpeStack.Push(*p);
}


//void CExpressionHandler::MoveToNextCharacter()
//{
//	m_pCurrent++;
//}


void CExpressionHandler::Execute()
{
	//m_OpeStack.Push(_T('#'));
	while (*m_pCurrent)
	{
		if (IsDigital(m_pCurrent))
		{
			PushNumber();//m_pCurrent++;
		}
		else
		{
			if (IsHigherThanStackTop(m_pCurrent))//
			{
				PushOperator(m_pCurrent);
				/*while (!IsDigital(m_pCurrent))
				{
					m_pCurrent++;
				}*/
				m_pCurrent++;
			}
			else
			{
				//do{PushResult();}
				//do{ PushStack(); }
				//while(!IsHigherThanStackTop(m_pCurrent));					
				do{ PushStack(); } 
				while (!IsHigherThanStackTop(m_pCurrent));
				PushOperator(m_pCurrent);
				/*while (!IsDigital(m_pCurrent))
				{
					m_pCurrent++;
				}*/
				m_pCurrent++;
			}
		}
	}
}


void CExpressionHandler::InitialPoint()
{
	m_pCurrent = m_strExpression.GetBuffer(5);//1
}


void CExpressionHandler::SetExpression(CString strExpression)
{

	m_strExpression = strExpression;
}


CString CExpressionHandler::GetResult()
{
	CString strResult;
	strResult.Format(_T("%f"), m_NumStack.Pop());
	while (strResult.Right(1)==_T('0'))
	{
		strResult.Delete(strResult.GetLength() - 1);
		if (strResult.Right(1) == _T('.'))
		{
			strResult.Delete(strResult.GetLength() - 1);
			break;
		}
	}
	return strResult;
}


void CExpressionHandler::Run()
{
	InitialPoint();
	Execute();
}


bool CExpressionHandler::ComparePriority(TCHAR * cp, TCHAR * p)
{
	if (GetPriority(*cp) >= GetPriority(*p))
	return false;
	else return true;
}
