// successDlg.h : ͷ�ļ�
//

#pragma once


// CsuccessDlg �Ի���
class CsuccessDlg : public CDialog
{
// ����
public:
	CsuccessDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SUCCESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();                               //��ʼ���Ի�����InitInstance��ͬ�������ǳ�ʼ��Ӧ�ó���
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// ӳ����ַ�
	CString m_strInputBox;
public:
	afx_msg void OnEnChangeEditnode();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
