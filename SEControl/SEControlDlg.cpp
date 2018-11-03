
// SEControlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <fstream>
#include "GEP.H"
#include "SEControlDlg.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSEControlDlg 对话框



CSEControlDlg::CSEControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SECONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//instance = this;
	/*使用redis必须添加上去*/
	WSAData wsaData;
	WSAStartup(MAKEWORD(1, 1), &wsaData);
}

void CSEControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSEControlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_OPEN, &CSEControlDlg::OnBnClickedOpen)
	ON_BN_CLICKED(IDC_CLOSE, &CSEControlDlg::OnBnClickedClose)
	ON_BN_CLICKED(ID_RESET, &CSEControlDlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_OPENL, &CSEControlDlg::OnBnClickedOpenl)
	ON_BN_CLICKED(IDC_CLOSEL, &CSEControlDlg::OnBnClickedClosel)
	ON_BN_CLICKED(IDC_RESETL, &CSEControlDlg::OnBnClickedResetl)
	ON_BN_CLICKED(IDC_LED, &CSEControlDlg::OnBnClickedLed)
END_MESSAGE_MAP()


// CSEControlDlg 消息处理程序

BOOL CSEControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//ComListInit();
	// TODO: 在此添加额外的初始化代码
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	固高运动控制卡
	*/
	//rtn = GT_Close();  //关闭运动控制卡
	//error(rtn);
	//rtn = GT_Open();  //打开运动控制卡
	//error(rtn);
	//rtn = GT_HardRst();  //初始化运动控制卡
	//error(rtn);
	///////////////////////////////////////////////////////////////////////////////////////////////////

	lpPara[0] = _T("openCamera1");
	lpPara[1] = _T("openCamera2");
	lpPara[2] = _T("openCamera3");
	lpPara[3] = _T("openCamera4");
	lpPara[4] = _T("openCamera5");
	lpPara[5] = _T("openCamera6");
	SetDlgItemInt(IDC_NAME, 0, 0);
	SetDlgItemInt(IDC_NAMEL, 0, 0);
	GetDlgItem(IDC_CLOSE)->EnableWindow(false);
	GetDlgItem(IDC_CLOSEL)->EnableWindow(false);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSEControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSEControlDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSEControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSEControlDlg::OnBnClickedOpen()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	CreateProcess 方法
	*/
	ZeroMemory(&StartupInfo[0], sizeof(StartupInfo[0]));
	ZeroMemory(&StartupInfo[1], sizeof(StartupInfo[1]));
	ZeroMemory(&StartupInfo[2], sizeof(StartupInfo[2]));
	ZeroMemory(&StartupInfo[3], sizeof(StartupInfo[3]));
	ZeroMemory(&StartupInfo[4], sizeof(StartupInfo[4]));
	ZeroMemory(&StartupInfo[5], sizeof(StartupInfo[5]));
	StartupInfo[0].cb = sizeof(StartupInfo[0]);
	StartupInfo[1].cb = sizeof(StartupInfo[1]);
	StartupInfo[2].cb = sizeof(StartupInfo[2]);
	StartupInfo[3].cb = sizeof(StartupInfo[3]);
	StartupInfo[4].cb = sizeof(StartupInfo[4]);
	StartupInfo[5].cb = sizeof(StartupInfo[5]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[0], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[0], &ProcessInfo[0]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[1], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[1], &ProcessInfo[1]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[2], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[2], &ProcessInfo[2]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[3], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[3], &ProcessInfo[3]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[4], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[4], &ProcessInfo[4]);
	CreateProcess(_T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara[5], NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[5], &ProcessInfo[5]);

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	ShellExecute 方法
	*/
	/*lpPara = _T("openCamera1");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);
	lpPara = _T("openCamera2");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);
	lpPara = _T("openCamera3");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);
	lpPara = _T("openCamera4");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);
	lpPara = _T("openCamera5");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);
	lpPara = _T("openCamera6");
	ShellExecute(NULL, _T("open"), _T("..\\..\\ImageSaver\\release\\ImageSaver.exe"), lpPara, NULL, SW_SHOWNORMAL);*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	GetDlgItem(ID_OPEN)->EnableWindow(false);
	GetDlgItem(IDC_CLOSE)->EnableWindow(true);
}



void CSEControlDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//每次时间到都使用PubSubManager类的处理函数来判断是否有消息发布
	m_psM.OnTimer();
	CDialogEx::OnTimer(nIDEvent);
}




void CSEControlDlg::OnBnClickedClose()
{
	// TODO:  在此添加控件通知处理程序代码
	::TerminateProcess(ProcessInfo[0].hProcess, 0);
	::TerminateProcess(ProcessInfo[1].hProcess, 0);
	::TerminateProcess(ProcessInfo[2].hProcess, 0);
	::TerminateProcess(ProcessInfo[3].hProcess, 0);
	::TerminateProcess(ProcessInfo[4].hProcess, 0);
	::TerminateProcess(ProcessInfo[5].hProcess, 0);
	GetDlgItem(ID_OPEN)->EnableWindow(true);
	GetDlgItem(IDC_CLOSE)->EnableWindow(false);
}


void CSEControlDlg::OnBnClickedReset()
{
	// TODO:  在此添加控件通知处理程序代码
	string files[6] = { _T("E:\\document\\subway_tunnel_program\\data\\image\\cam1.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam2.txt"),
		                _T("E:\\document\\subway_tunnel_program\\data\\image\\cam3.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam4.txt"),
						_T("E:\\document\\subway_tunnel_program\\data\\image\\cam5.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam6.txt") };
	int temp;
	
	for (string file : files)
	{
		temp = GetDlgItemInt(IDC_NAME, NULL, 0);//读取第一个名字的序号
		ofstream namefile(file, ios::trunc);	/*由于重置的数字长度可能小于TXT文件中保留的数字长度，如果直接把文件光标移到最开始（下一句代码），则会导致命名错误。如:
												TXT文件中保存的数字是100，如果想重置为20，输入20后，光标移到最开始，TXT文件会被重写为200，显然不对，所以需要清空。而在
												前面保存图像的代码中，TXT文件的数字是用“++”来实现累加的，所以后面重写的数字长度一定不比之前的短，所以没问题。
												*/
		/*namefile.seekg(0, ios::beg);*/
		namefile << temp;
		namefile.close();
	}
	
}


void CSEControlDlg::OnBnClickedOpenl()
{
	// TODO:  在此添加控件通知处理程序代码
	ZeroMemory(&StartupInfo[6], sizeof(StartupInfo[6]));
	StartupInfo[6].cb = sizeof(StartupInfo[6]);
	CreateProcess(_T("E:\\document\\subway_tunnel_program\\LMSDEMO_Example\\bin\\Debug\\LMS_connectionExample.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[6], &ProcessInfo[6]);
	GetDlgItem(IDC_OPENL)->EnableWindow(false);
	GetDlgItem(IDC_CLOSEL)->EnableWindow(true);
}


void CSEControlDlg::OnBnClickedClosel()
{
	// TODO:  在此添加控件通知处理程序代码
	::TerminateProcess(ProcessInfo[6].hProcess, 0);
	GetDlgItem(IDC_OPENL)->EnableWindow(true);
	GetDlgItem(IDC_CLOSEL)->EnableWindow(false);
}


void CSEControlDlg::OnBnClickedResetl()
{
	// TODO:  在此添加控件通知处理程序代码
	string file = _T("E:\\document\\subway_tunnel_program\\data\\LMS\\flag.txt");
	int temp;

	temp = GetDlgItemInt(IDC_NAMEL, NULL, 0);//读取第一个名字的序号
	ofstream namefile(file, ios::trunc);	/*由于重置的数字长度可能小于TXT文件中保留的数字长度，如果直接把文件光标移到最开始（下一句代码），则会导致命名错误。如:
												TXT文件中保存的数字是100，如果想重置为20，输入20后，光标移到最开始，TXT文件会被重写为200，显然不对，所以需要清空。而在
												前面保存图像的代码中，TXT文件的数字是用“++”来实现累加的，所以后面重写的数字长度一定不比之前的短，所以没问题。
												*/
	/*namefile.seekg(0, ios::beg);*/
	namefile << temp;
	namefile.close();
	

}


void CSEControlDlg::OnBnClickedLed()
{
	if (ledflag == 0)
	{
		GT_ExOpt(0x4);//比较端口(0x4和0x2)电压不一致，打开led
		ledflag = 1;
	}
	else if (ledflag == 1)
	{
		GT_ExOpt(0x4);//比较端口(0x4和0x2)电压一致，关闭led
		GT_ExOpt(0x2);
		ledflag = 0;
	}
	else
	{
		GT_ExOpt(0x4);
		ledflag = 1;
	}
} 

void error(short rtn)
{
	switch (rtn)
	{
	case  -1: printf("\a\nCommunication Error !");
		break;
	case  0:
		break;
	case  1: printf("\a\nCommand Error !");
		break;
	case  2: printf("\a\nRadius or chord is 0 !");
		break;
	case  3: printf("\a\nLength is 0 or overflow !");
		break;
	case  4: printf("\a\nVelocity or acceleration is less then 0 !");
		break;
	case  5: printf("\a\nChord is greater than diameter !");
		break;
	case  7: printf("\a\nParameter error !");
		break;
	default: printf("\a\nError Code = %d ", rtn);
		break;
	}
}
