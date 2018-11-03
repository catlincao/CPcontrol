
// SEControlDlg.h : 头文件
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



// CSEControlDlg 对话框
class CSEControlDlg : public CDialogEx
{
// 构造
public:
CSEControlDlg(CWnd* pParent = NULL);	// 标准构造函数


	//redis 的参数定义
	CString m_ipAddr;
	int m_Port;
	CString m_Channel;
	CString m_message;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECONTROL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	int cam_index;   //相机索引
	CComboBox m_choseCAM;
	LPTSTR lpPara[6];   // 打开相机的参数
	PROCESS_INFORMATION ProcessInfo[7]; //用于CreatProcess的参数
	STARTUPINFO StartupInfo[7];
	int ledflag = 0;
	int rtn;

	PubSubManager m_psM;
	/*static CSEControlDlg *instance;*/
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnCbnSelchangeCombo1();
	// 相机列表
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
