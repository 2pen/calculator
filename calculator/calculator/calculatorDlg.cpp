// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "ExpressionHander.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalculatorDlg::IDD, pParent)
	, m_StrIputbox(_T(""))
	, m_Ifzero(false)    //用了
	, m_Ifnum2(true)  //针对00008这种错误
	, m_Ifnum(false)//还没有用
	, m_Iflr(false)
	, k(0)
	, m_Ifzero2(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EDIT, m_StrIputbox);
	DDV_MaxChars(pDX, m_StrIputbox, 50);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_0, &CcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CcalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CcalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CcalculatorDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CcalculatorDlg::OnBnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_SSUB, &CcalculatorDlg::OnBnClickedButtonSsub)
	ON_BN_CLICKED(IDC_BUTTON_CLS, &CcalculatorDlg::OnBnClickedButtonCls)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CcalculatorDlg::OnBnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_L, &CcalculatorDlg::OnBnClickedButtonL)
	ON_BN_CLICKED(IDC_BUTTON_R, &CcalculatorDlg::OnBnClickedButtonR)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CcalculatorDlg::OnBnClickedButtonEqu)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	

			if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("1"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("1"));}
}

void CcalculatorDlg::OnBnClickedButton0()
{
	if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("0"));
		m_Ifzero=false;
		}
		else{												//处理0.9



	if(m_Ifzero2)
		return;
	if(m_StrIputbox.Right(1) == _T("+")||m_StrIputbox.Right(1) == _T("-")||m_StrIputbox.Right(1) == _T("x")||m_StrIputbox.Right(1) == _T("÷"))
	m_Ifzero2=true;
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
	if(m_StrIputbox.Right(1)<_T("0")||m_StrIputbox.Right(1)>_T("9"))
	{
		if(m_StrIputbox.Right(1)!=_T("."))
		   m_Ifzero=true;
	}
	OnDealnum(_T("0"));}                                //处理0.9
	// TODO: 在此添加控件通知处理程序代码
	

}

void CcalculatorDlg::OnDealnum(CString num)
{
	
	if (m_StrIputbox != _T("0"))
	{
		
		m_StrIputbox += num;
	}
	else
	{
		if(num==".")
          m_StrIputbox += num;  //判断0.5的情况
		else
	     m_StrIputbox = num;
	}
	     m_Ifnum = true;
	     UpdateData(false);

}

void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("2"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("2"));}
}

void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("3"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("3"));}
}

void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("4"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("4"));}
}

void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("5"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("5"));}
}

void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("6"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("6"));}
}

void CcalculatorDlg::OnBnClickedButton7()
{

			if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("7"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("7"));}
}

void CcalculatorDlg::OnBnClickedButton8()
{

			if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("8"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("8"));}
}

void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //处理0.9
		{
		OnDealnum(_T("9"));
		m_Ifzero=false;
		}
		else{												//处理0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("9"));}
}

void CcalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码

	if(m_StrIputbox.Right(1)==_T("+")||m_StrIputbox.Right(1)==_T("-")||m_StrIputbox.Right(1)==_T("x")||m_StrIputbox.Right(1)==_T("÷"))
		return;
	if(m_StrIputbox.Right(1)<_T("0")&&m_StrIputbox.Right(1)>_T("9")||m_StrIputbox.Right(1)==_T(".")||m_StrIputbox.Right(1)==_T(""))
		return;
	else
	{
		if(m_Ifnum2==true)
		{
		OnDealnum(_T("."));
		m_Ifzero2=false;
	    m_Ifnum2=false;
		}
	}

}
void CcalculatorDlg::OnBnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_StrIputbox.Right(1) == _T(")"))
		k++;
	if(m_StrIputbox.Right(1) == _T("("))
		k--;
	
	if (m_StrIputbox.Right(1) == _T("."))
		m_Ifnum2= true;

	m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
	UpdateData(false);
}


	

bool CcalculatorDlg::IsDot(CString c)
{
	
	if (c >= _T("0")&&c <= _T("9") || c == _T("."))
		return  false;
	else
	return  true;
	
}

void CcalculatorDlg::OnBnClickedButtonPlus()
{

	OnDealope(_T("+"));
}

void CcalculatorDlg::OnBnClickedButtonSub()
{
	// TODO: 在此添加控件通知处理程序代码
	OnDealope(_T("-"));

}

void CcalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: 在此添加控件通知处理程序代码
	/*OnDealnum(_T("x"));
	 m_Ifnum2=true;*/
	OnDealope(_T("x"));
}

void CcalculatorDlg::OnBnClickedButtonSsub()
{
	// TODO: 在此添加控件通知处理程序代码
	/*OnDealnum(_T("/"));
	 m_Ifnum2=true;*/
	OnDealope(_T("÷"));
}

void CcalculatorDlg::OnBnClickedButtonCls()
{
	// TODO: 在此添加控件通知处理程序代码
	m_StrIputbox = _T("");
	UpdateData(false);
	//m_Ifnum2=true;
	//k=0;
	//m_Ifzero2=false;

	m_Ifzero=false;    //用了
	 m_Ifnum2=true; //针对00008这种错误
	 m_Ifnum=false;//还没有用
	 m_Iflr=false;
	 k=0;
	 m_Ifzero2=false;

}


void CcalculatorDlg::OnDealope(CString num)
{

	if(m_StrIputbox.Right(1)==_T(")"))
	{
	OnDealnum(num);
	 m_Ifnum2=true;
	}else{
	if(m_StrIputbox.Right(1)<_T("0")||m_StrIputbox.Right(1)>_T("9")||m_StrIputbox.Right(1)== _T("."))
		return;
	else
	{
	OnDealnum(num);
	 m_Ifnum2=true;
	}
	}
}

void CcalculatorDlg::OnBnClickedButtonL()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_StrIputbox.Right(1)==_T("")||m_StrIputbox.Right(1)==_T("+")||m_StrIputbox.Right(1)==_T("-")||m_StrIputbox.Right(1)==_T("x")||m_StrIputbox.Right(1)==_T("÷"))
	{
		
	
 m_StrIputbox +=_T("(");
 UpdateData(false);
k++;
	}
	
}

void CcalculatorDlg::OnBnClickedButtonR()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_StrIputbox.Right(1)>=_T("0")&&m_StrIputbox.Right(1)<=_T("9")||m_StrIputbox.Right(1)==_T("(")||m_StrIputbox.Right(1)==_T(")"))
	{
		if(k>=1)
		{
		m_StrIputbox +=_T(")");
		UpdateData(false);
		k--;
		}
	}
}






 void CcalculatorDlg::OnBnClickedButtonEqu()
 {
	


	 // TODO: 在此添加控件通知处理程序代码
		m_StrIputbox += _T("=");
		UpdateData(false);
		CExpressionHander handler;
		handler.SetExpression(m_StrIputbox);
		handler.Run();
		m_StrIputbox = handler.GetValue();
		while(m_StrIputbox.Right(1)==_T("0"))
		{
			//if(m_StrIputbox.Right(3)!=_T("."))
				
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			
		}
		if(m_StrIputbox.Right(1)==_T("."))
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);


		UpdateData(false);


 }

