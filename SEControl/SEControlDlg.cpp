
// SEControlDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CSEControlDlg �Ի���



CSEControlDlg::CSEControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SECONTROL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//instance = this;
	/*ʹ��redis���������ȥ*/
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


// CSEControlDlg ��Ϣ�������

BOOL CSEControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	
	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��
	//ComListInit();
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	///////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	�̸��˶����ƿ�
	*/
	//rtn = GT_Close();  //�ر��˶����ƿ�
	//error(rtn);
	//rtn = GT_Open();  //���˶����ƿ�
	//error(rtn);
	//rtn = GT_HardRst();  //��ʼ���˶����ƿ�
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CSEControlDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CSEControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSEControlDlg::OnBnClickedOpen()
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	CreateProcess ����
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
	ShellExecute ����
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//ÿ��ʱ�䵽��ʹ��PubSubManager��Ĵ��������ж��Ƿ�����Ϣ����
	m_psM.OnTimer();
	CDialogEx::OnTimer(nIDEvent);
}




void CSEControlDlg::OnBnClickedClose()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	string files[6] = { _T("E:\\document\\subway_tunnel_program\\data\\image\\cam1.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam2.txt"),
		                _T("E:\\document\\subway_tunnel_program\\data\\image\\cam3.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam4.txt"),
						_T("E:\\document\\subway_tunnel_program\\data\\image\\cam5.txt"), _T("E:\\document\\subway_tunnel_program\\data\\image\\cam6.txt") };
	int temp;
	
	for (string file : files)
	{
		temp = GetDlgItemInt(IDC_NAME, NULL, 0);//��ȡ��һ�����ֵ����
		ofstream namefile(file, ios::trunc);	/*�������õ����ֳ��ȿ���С��TXT�ļ��б��������ֳ��ȣ����ֱ�Ӱ��ļ�����Ƶ��ʼ����һ����룩����ᵼ������������:
												TXT�ļ��б����������100�����������Ϊ20������20�󣬹���Ƶ��ʼ��TXT�ļ��ᱻ��дΪ200����Ȼ���ԣ�������Ҫ��ա�����
												ǰ�汣��ͼ��Ĵ����У�TXT�ļ����������á�++����ʵ���ۼӵģ����Ժ�����д�����ֳ���һ������֮ǰ�Ķ̣�����û���⡣
												*/
		/*namefile.seekg(0, ios::beg);*/
		namefile << temp;
		namefile.close();
	}
	
}


void CSEControlDlg::OnBnClickedOpenl()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ZeroMemory(&StartupInfo[6], sizeof(StartupInfo[6]));
	StartupInfo[6].cb = sizeof(StartupInfo[6]);
	CreateProcess(_T("E:\\document\\subway_tunnel_program\\LMSDEMO_Example\\bin\\Debug\\LMS_connectionExample.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &StartupInfo[6], &ProcessInfo[6]);
	GetDlgItem(IDC_OPENL)->EnableWindow(false);
	GetDlgItem(IDC_CLOSEL)->EnableWindow(true);
}


void CSEControlDlg::OnBnClickedClosel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	::TerminateProcess(ProcessInfo[6].hProcess, 0);
	GetDlgItem(IDC_OPENL)->EnableWindow(true);
	GetDlgItem(IDC_CLOSEL)->EnableWindow(false);
}


void CSEControlDlg::OnBnClickedResetl()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	string file = _T("E:\\document\\subway_tunnel_program\\data\\LMS\\flag.txt");
	int temp;

	temp = GetDlgItemInt(IDC_NAMEL, NULL, 0);//��ȡ��һ�����ֵ����
	ofstream namefile(file, ios::trunc);	/*�������õ����ֳ��ȿ���С��TXT�ļ��б��������ֳ��ȣ����ֱ�Ӱ��ļ�����Ƶ��ʼ����һ����룩����ᵼ������������:
												TXT�ļ��б����������100�����������Ϊ20������20�󣬹���Ƶ��ʼ��TXT�ļ��ᱻ��дΪ200����Ȼ���ԣ�������Ҫ��ա�����
												ǰ�汣��ͼ��Ĵ����У�TXT�ļ����������á�++����ʵ���ۼӵģ����Ժ�����д�����ֳ���һ������֮ǰ�Ķ̣�����û���⡣
												*/
	/*namefile.seekg(0, ios::beg);*/
	namefile << temp;
	namefile.close();
	

}


void CSEControlDlg::OnBnClickedLed()
{
	if (ledflag == 0)
	{
		GT_ExOpt(0x4);//�Ƚ϶˿�(0x4��0x2)��ѹ��һ�£���led
		ledflag = 1;
	}
	else if (ledflag == 1)
	{
		GT_ExOpt(0x4);//�Ƚ϶˿�(0x4��0x2)��ѹһ�£��ر�led
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
