
// SEControlDlg.h : ͷ�ļ�
//

#pragma once
#include "PubSubManager.h"
#include "SEControl.h"
#include "afxwin.h"
#include "afxcmn.h"
#include "Windows.h"
#include <winbase.h>
#include "afxdialogex.h"
#include <afxwin.h>



// CSEControlDlg �Ի���
class CSEControlDlg : public CDialogEx
{
// ����
public:
CSEControlDlg(CWnd* pParent = NULL);	// ��׼���캯��


	//redis �Ĳ�������
	CString m_ipAddr;
	int m_Port;
	CString m_Channel;
	CString m_message;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	int cam_index;   //�������
	CComboBox m_choseCAM;
	LPTSTR lpPara[6];   // ������Ĳ���
	PROCESS_INFORMATION ProcessInfo[7]; //����CreatProcess�Ĳ���
	STARTUPINFO StartupInfo[7];
	int ledflag = 0;
	int rtn;

	PubSubManager m_psM;
	/*static CSEControlDlg *instance;*/
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnCbnSelchangeCombo1();
	// ����б�
	//void ComListInit();
	afx_msg void OnBnClickedOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedReset();
	afx_msg void OnBnClickedOpenl();
	afx_msg void OnBnClickedClosel();
	afx_msg void OnBnClickedResetl();
	afx_msg void OnBnClickedLed();
};
