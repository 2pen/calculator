// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "ExpressionHander.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalculatorDlg::IDD, pParent)
	, m_StrIputbox(_T(""))
	, m_Ifzero(false)    //����
	, m_Ifnum2(true)  //���00008���ִ���
	, m_Ifnum(false)//��û����
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


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

			if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("1"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("1"));}
}

void CcalculatorDlg::OnBnClickedButton0()
{
	if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("0"));
		m_Ifzero=false;
		}
		else{												//����0.9



	if(m_Ifzero2)
		return;
	if(m_StrIputbox.Right(1) == _T("+")||m_StrIputbox.Right(1) == _T("-")||m_StrIputbox.Right(1) == _T("x")||m_StrIputbox.Right(1) == _T("��"))
	m_Ifzero2=true;
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
	if(m_StrIputbox.Right(1)<_T("0")||m_StrIputbox.Right(1)>_T("9"))
	{
		if(m_StrIputbox.Right(1)!=_T("."))
		   m_Ifzero=true;
	}
	OnDealnum(_T("0"));}                                //����0.9
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	

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
          m_StrIputbox += num;  //�ж�0.5�����
		else
	     m_StrIputbox = num;
	}
	     m_Ifnum = true;
	     UpdateData(false);

}

void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("2"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("2"));}
}

void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("3"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("3"));}
}

void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("4"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("4"));}
}

void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("5"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("5"));}
}

void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("6"));
		m_Ifzero=false;
		}
		else{												//����0.9
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
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("7"));
		m_Ifzero=false;
		}
		else{												//����0.9
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
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("8"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("8"));}
}

void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		if(m_StrIputbox.Right(1) == _T(")"))
		return;
		if(m_StrIputbox.Right(1) == _T("."))                  //����0.9
		{
		OnDealnum(_T("9"));
		m_Ifzero=false;
		}
		else{												//����0.9
		if(m_Ifzero)
	{
			m_StrIputbox.Delete(m_StrIputbox.GetLength()-1);
			m_Ifzero=false;
	}
		OnDealnum(_T("9"));}
}

void CcalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	if(m_StrIputbox.Right(1)==_T("+")||m_StrIputbox.Right(1)==_T("-")||m_StrIputbox.Right(1)==_T("x")||m_StrIputbox.Right(1)==_T("��"))
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnDealope(_T("-"));

}

void CcalculatorDlg::OnBnClickedButtonMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*OnDealnum(_T("x"));
	 m_Ifnum2=true;*/
	OnDealope(_T("x"));
}

void CcalculatorDlg::OnBnClickedButtonSsub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*OnDealnum(_T("/"));
	 m_Ifnum2=true;*/
	OnDealope(_T("��"));
}

void CcalculatorDlg::OnBnClickedButtonCls()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StrIputbox = _T("");
	UpdateData(false);
	//m_Ifnum2=true;
	//k=0;
	//m_Ifzero2=false;

	m_Ifzero=false;    //����
	 m_Ifnum2=true; //���00008���ִ���
	 m_Ifnum=false;//��û����
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_StrIputbox.Right(1)==_T("")||m_StrIputbox.Right(1)==_T("+")||m_StrIputbox.Right(1)==_T("-")||m_StrIputbox.Right(1)==_T("x")||m_StrIputbox.Right(1)==_T("��"))
	{
		
	
 m_StrIputbox +=_T("(");
 UpdateData(false);
k++;
	}
	
}

void CcalculatorDlg::OnBnClickedButtonR()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	


	 // TODO: �ڴ���ӿؼ�֪ͨ����������
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

