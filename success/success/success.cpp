// success.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "success.h"
#include "successDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsuccessApp

BEGIN_MESSAGE_MAP(CsuccessApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CsuccessApp ����

CsuccessApp::CsuccessApp()                                                            //���캯��
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CsuccessApp ����

CsuccessApp theApp;      //һ��������theApp���󣬳���Ϳ�ʼִ���ˣ���ڣ���


// CsuccessApp ��ʼ��

BOOL CsuccessApp::InitInstance()                                            ��CsuccessApp���ж�����CsuccessDlg ��Ķ���
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CsuccessDlg dlg;
	m_pMainWnd = &dlg;                                                  //m_pMainWind��CWinApp���ж�����ˣ��������ڵ�ָ��
	INT_PTR nResponse = dlg.DoModal();                                    //��ʾ�Ի���   dlg.DoModal
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
