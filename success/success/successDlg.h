// successDlg.h : 头文件
//

#pragma once


// CsuccessDlg 对话框
class CsuccessDlg : public CDialog
{
// 构造
public:
	CsuccessDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SUCCESS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();                               //初始化对话框，与InitInstance不同，后者是初始化应用程序
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// 映射表字符
	CString m_strInputBox;
public:
	afx_msg void OnEnChangeEditnode();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
