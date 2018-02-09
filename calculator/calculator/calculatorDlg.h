// calculatorDlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialog
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
private:
	// �ַ���ӳ�䵽����
	CString m_StrIputbox;
public:
	afx_msg void OnBnClickedButton0();
private:
	bool m_Ifzero;
	bool m_Ifnum2;
	void OnDealnum(CString num);
	bool m_Ifnum;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDot();
private:
	bool IsDot(CString c);
public:
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnBnClickedButtonSsub();
	afx_msg void OnBnClickedButtonCls();
	afx_msg void OnBnClickedButtonBack();
private:
	void OnDealope(CString num);
public:
	afx_msg void OnBnClickedButtonL();
private:
	bool m_Iflr;
	// ��������
	int k;
public:
	afx_msg void OnBnClickedButtonR();
private:
	bool m_Ifzero2;
public:
	afx_msg void OnBnClickedButtonEqu();
;
};
