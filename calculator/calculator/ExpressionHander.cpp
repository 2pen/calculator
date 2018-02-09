
#include "stdafx.h"
#include "ExpressionHander.h"


 CExpressionHander::CExpressionHander()
{
	 bError=false;
}


CExpressionHander::~CExpressionHander()
{
}


bool CExpressionHander::IsDigital(TCHAR c)

{
	if (c >= '0'&&c <= '9' || c == '.')
		return  true;
	else
		return  false;
	
}


int CExpressionHander::IsHighPriority(TCHAR first, TCHAR last)

{
	
	
	if (first == ')')
	{
		if (last == '(')
			return 0;
		else
			return  1;
	}

	if (first == '(' || last == '(')
	{
		return -1;
	}

	
if (Getpriority(first) >= Getpriority(last))
		return 1;
	else
		return -1;	
}


int CExpressionHander::Getpriority(TCHAR c)
{
	switch(c)
	{
	    case _T('x'):
	    case _T('¡Â'): return 1;
	    case _T('+'):
		case _T('-'): return 3;
		case _T('=') :
		return 5;
		default: return 20;

	
	}

	return  0;
	
}


double CExpressionHander::GetResult(double dX, double dY, TCHAR cOpt)
{
	
	switch (cOpt) 
	{
	case _T('x'):  return dX * dY;
	case _T('¡Â'):  
		if (dY != 0)
			return dX / dY;
		else
		    bError=true;
	        //Å×³ö³ý0´íÒì³£
    case _T('+'):  return dX + dY;
	case _T('-'):  return dX - dY;
	case _T('sin'): return sin(dX);
	
} 
	return 0;
}


void CExpressionHander::PushOperator(TCHAR c)
{
	m_OptStack.Push(c);


}


void CExpressionHander::PushNum(double dX)
{
	m_NumStack.Push(dX);

}


void CExpressionHander::StoreNumber()
{

	double dX = _tstof(m_pCurrent);
	PushNum(dX);

}


void CExpressionHander::MoveToNextOperator()
{
	while (IsDigital(*m_pCurrent))

	{ 
		m_pCurrent++;

    }

}


void CExpressionHander::MoveToNextNumber()
{

	m_pCurrent++;
}


void CExpressionHander::PreParedOperationData(double &dX, double &dY, TCHAR &cOpt)
{
cOpt = m_OptStack.Pop();
dY = m_NumStack.Pop();
dX = m_NumStack.Pop();

}


void CExpressionHander::ScanExpression()
{

	while (IsNotEnd())
	{
		if (IsDigital(*m_pCurrent))
		{  

			StoreNumber();
			MoveToNextOperator();
		}

		else
		  {
			switch(IsHighPriority(*m_pCurrent, m_OptStack.Top()))
			{   case -1:
				PushOperator(*m_pCurrent);
				MoveToNextNumber();
				break;
			case  1:

				double  dX , dY ;
				TCHAR  cOpt ;

				    PreParedOperationData( dX,  dY,  cOpt);
					PushNum(GetResult(dX, dY, cOpt));
					break;
			
			case 0:

				m_OptStack.Pop();
				MoveToNextNumber();
				break;



			}
		}
}



}


bool CExpressionHander::IsNotEnd()
{
       if (*m_pCurrent)
	   return true;
	   else
	   return  false;
}


void CExpressionHander::SetExpression(CString expression)
{

	m_strExpresssion = expression;
	m_pCurrent = m_strExpresssion.GetBuffer();
}


void CExpressionHander::Run()
{
	ScanExpression();
}


CString CExpressionHander::GetValue()
{
	if (!bError)
		m_strResult.Format(_T("%.10f"), m_NumStack.Top());
	else
		m_strResult = "Dividing Zero Error!";

	    return m_strResult;
}
