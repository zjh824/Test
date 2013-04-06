// SERVODlg.cpp : implementation file
//

#include "stdafx.h"
#include "SERVO.h"
#include "SERVODlg.h"
#include "pci_8164.h"
#include "LJV7_IF.h"
#include "LJV7_ErrorCode.h"
#include <iostream>
#include <fstream>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define TotalAxis 4

ofstream of;
double pos[TotalAxis];
I16 bstop=0,ISR_ON=0;
I32 int_counter[TotalAxis]={0,0,0,0};
I16 AxisNo=0;
int a = 0;
HANDLE hEvent[TotalAxis];
CWinThread *pThread[TotalAxis];
bool bStart = false;


LJV7IF_MEASURE_DATA data[40][16];


UINT IntThreadProc( LPVOID lpParam )
{
	int n;

	n=(int)lpParam;


//	U32 errStatus;
//	U32 intStatus;
	SetThreadPriority(GetCurrentThread(),  THREAD_PRIORITY_TIME_CRITICAL);
	while( ISR_ON )
	{

		WaitForSingleObject(hEvent[n],INFINITE);
		
		int_counter[n]++;
		if(n== 1)
		{
//			_8164_get_int_status(1, &errStatus, &intStatus);
			
//			if(intStatus == 0x1000)
			{
				LJV7IF_Trigger(0);
			//	Sleep(5);
//				LJV7IF_GetMeasurementValue(0,data[a]);
				a ++;
			}
		
		}

		ResetEvent(hEvent[n]);
	}
	
	return TRUE;
}

void DoEvents(void)
{
	MSG message;

	while( :: PeekMessage(&message,NULL,0,0,PM_REMOVE) )
	{
		::TranslateMessage(&message);
		::DispatchMessage(&message);
	}
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSERVODlg dialog

CSERVODlg::CSERVODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSERVODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSERVODlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSERVODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSERVODlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSERVODlg, CDialog)
	//{{AFX_MSG_MAP(CSERVODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SVON, OnSvon)
	ON_BN_CLICKED(IDC_SVOFF, OnSvoff)
	ON_BN_CLICKED(IDC_PRMOVE, OnPrmove)
	ON_BN_CLICKED(IDC_MRMOVE, OnMrmove)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_HOME, OnHome)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_CUT, OnCut)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_COMPARE, OnButtonCompare)
	ON_BN_CLICKED(IDC_BUTTON_EVTINT, OnButtonEvtint)
	ON_BN_CLICKED(IDC_BUTTON_ERRINT, OnButtonErrint)
	ON_BN_CLICKED(IDC_BUTTON_INTLJV, OnButtonIntljv)
	ON_BN_CLICKED(IDC_BUTTON_ETHOPEN, OnButtonEthopen)
	ON_BN_CLICKED(IDC_BUTTON_TRIG, OnButtonTrig)
	ON_BN_CLICKED(IDC_BUTTON_GETVALUE, OnButtonGetvalue)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, OnButtonZero)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON_GETDATA, OnButtonGetdata)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, CSERVODlg::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSERVODlg message handlers

BOOL CSERVODlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	of.open("d:\\1.txt", ios::out | ios::app  );
	memset(data, 40 * 16 * sizeof(LJV7IF_MEASURE_DATA), 0);

	if(!of.is_open())
	{
		AfxMessageBox("open file fail!!!");
	}
	
	I16 TotalCard,Err;
	CString SErr;

	_8164_initial(&TotalCard);

	if( TotalCard == 0 )
	{
		SErr.Format("No PCI-8164 Found!");
		AfxMessageBox(SErr);
	}

	char SysDir[1024];
	CString FullPath;
	CString ConfigFile="\\system32\\8164.ini";
	GetWindowsDirectory(SysDir,1024);
	FullPath=SysDir;
	FullPath+=ConfigFile;

	// Get The INI file from Motion Creator
	Err=_8164_config_from_file(FullPath.GetBuffer(0));
	if( Err )
	{
		SErr.Format("8164.ini file not found!");
		AfxMessageBox(SErr);
	}

	_8164_int_enable(0,hEvent);
//	_8164_set_int_factor(1, 0xffff);

	_8164_int_control(0,1);

	ISR_ON=1;

	for(int i=0;i<TotalAxis;i++)
	{
		pThread[i]=AfxBeginThread(IntThreadProc,(LPVOID)i,THREAD_PRIORITY_NORMAL,0,CREATE_SUSPENDED);
		ASSERT( pThread[i] );
		pThread[i]->m_bAutoDelete=FALSE;
		pThread[i]->ResumeThread();
	}

	SetTimer(1,80,NULL);

	CComboBox *pCombo;
	pCombo=(CComboBox *)GetDlgItem(IDC_COMBO1);

	pCombo->SetCurSel(0);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSERVODlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSERVODlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSERVODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CSERVODlg::OnSvon() 
{
	_8164_set_servo(AxisNo,0);	
}

void CSERVODlg::OnSvoff() 
{
	_8164_set_servo(AxisNo,1);	
}

void CSERVODlg::OnPrmove() 
{
	_8164_start_tr_move(AxisNo,90000,10000,50000,0.1,0.2);
	
}

void CSERVODlg::OnMrmove() 
{
	_8164_start_tr_move(AxisNo,-90000,10000,50000,0.1,0.2);
}


int n = 0;

void CSERVODlg::OnTimer(UINT_PTR nIDEvent) 
{
		
	unsigned short io_sts;
	unsigned short m_sts;
	char string[64];

	_8164_get_position(AxisNo,&pos[AxisNo]);
	_8164_get_io_status(AxisNo,&io_sts);
	m_sts=_8164_motion_done(AxisNo);

	SetDlgItemInt(IDC_INT,int_counter[AxisNo]);
	SetDlgItemInt(IDC_POS,(int)pos[AxisNo]);
	sprintf(string,"0x%x",io_sts);
	SetDlgItemText(IDC_IOSTS,string);
	SetDlgItemInt(IDC_MSTS,m_sts);


	SetDlgItemInt(IDC_EDIT_COMP,a);


	if(bStart)
	{
		n++;
		if(n == 10)
		{
			_8164_build_compare_function(AxisNo, 1,90000,  2250,1);
			_8164_set_auto_compare(AxisNo, 1);
			
			
			
			_8164_start_tr_move(AxisNo,90000,10000,50000,0.1,0.2);

		}
		else if(n == 40 )
		{
			
			_8164_start_tr_move(AxisNo,-90000,10000,50000,0.1,0.2);
			for(int i=0; i<40; ++i)
			{
				of << data[i][0].fValue << '\t' ;
			}
			of << endl;
			a= 0;
		}
		else if(n == 70)
		{
			n=0;
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CSERVODlg::OnOK() 
{

	ISR_ON=0;
	for(int i=0;i<TotalAxis;i++)
	{
		SetEvent(hEvent[i]);
		WaitForSingleObject(pThread[i]->m_hThread,INFINITE);
		delete pThread[i];
		_8164_set_servo(AxisNo,1);	
	}
		_8164_int_control(0,0);
	_8164_close();

	LJV7IF_CommClose(0);
	LJV7IF_Finalize();
	CDialog::OnOK();
}

void CSERVODlg::OnHome() 
{
	_8164_home_move(AxisNo,-1000,-5000,0.2);	
}

void CSERVODlg::OnStop() 
{
	_8164_sd_stop(AxisNo,0.1);	
	bstop=1;
}

void CSERVODlg::OnCut() 
{
	int flag=0;

	bstop=0;
	for(int i=0;i<1;i++)						// Loop counts
	{
		flag=1;
		_8164_start_tr_move(AxisNo,100000,0,80000,0.01,0.01);	// Forward motion
		while( _8164_motion_done(AxisNo) != 0 )				// Wait for done
		{
			if( pos[AxisNo] > 60000 && flag==1 )		// If moves to
			{									//   60000 counts
			  _8164_v_change(AxisNo,10000,0.1);			// Change speed
			  flag=0;
			}
			DoEvents();							// Deal other
		}										//   process

		if( bstop ) break;						// Break when
												//   stop command
		_8164_start_tr_move(AxisNo,-100000,0,80000,0.01,0.01);   // Reverse motion
		while( _8164_motion_done(AxisNo) !=0 )				// Wait for done
			DoEvents();

		if( bstop ) break;
		
	}
	bstop=0;
}


void CSERVODlg::OnSelchangeCombo1() 
{
	
	AxisNo=GetDlgItemInt(IDC_COMBO1);

}


void CSERVODlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼


	OnOK();
}

void CSERVODlg::OnButtonCompare() 
{
	// TODO: Add your control notification handler code here

	_8164_set_int_factor(AxisNo, 0x1000);
	_8164_set_trigger_type(AxisNo, 0);  //
//	_8164_set_general_comparator(AxisNo, 1, 1, 0, 1);
//	_8164_set_compare_mode(AxisNo, 4,1, 1, 0);
	_8164_set_trigger_comparator(AxisNo, 0, 1, 1);


//	_8164_start_tr_move(0, 36000, 0, 6000, 0.01,0.01);
	
}

void CSERVODlg::OnButtonEvtint() 
{
	// TODO: Add your control notification handler code here
	
}

void CSERVODlg::OnButtonErrint() 
{
	// TODO: Add your control notification handler code here
	
}

void CSERVODlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	
}

void CSERVODlg::OnButtonIntljv() 
{
	// TODO: Add your control notification handler code here

LJV7IF_Initialize();

	
}

void CSERVODlg::OnButtonEthopen() 
{
	// TODO: Add your control notification handler code here

	LJV7IF_ETHERNET_CONFIG  cfg;
	cfg.abyIpAddress[0] = 192;
	cfg.abyIpAddress[1] = 168;
	cfg.abyIpAddress[2] = 0;
	cfg.abyIpAddress[3] = 1;
	cfg.wPortNo = 24691;


	LJV7IF_EthernetOpen(0, &cfg);
}

void CSERVODlg::OnButtonTrig() 
{
	// TODO: Add your control notification handler code here
	LJV7IF_Trigger(0);
}

void CSERVODlg::OnButtonGetvalue() 
{
	// TODO: Add your control notification handler code here
	LJV7IF_MEASURE_DATA data[16];

	
	LJV7IF_GetMeasurementValue(0,data);



	CString str;
	str.Format("%f", data[0].fValue);
	SetDlgItemText(IDC_EDIT_VALUE,str);


}

void CSERVODlg::OnButtonZero() 
{
	// TODO: Add your control notification handler code here
	_8164_set_position(AxisNo, 0);
}

void CSERVODlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	_8164_build_compare_function(AxisNo, 1,90000,  2250,1);
	_8164_set_auto_compare(AxisNo, 1);
}

void CSERVODlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	bStart = true;
	n=0;

}

void CSERVODlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	bStart = false;
	n=0;	
}


void CSERVODlg::OnButtonGetdata() 
{
	// TODO: Add your control notification handler code here
	LJV7IF_GET_STORAGE_REQ *pReq = (LJV7IF_GET_STORAGE_REQ *)malloc(sizeof(LJV7IF_GET_STORAGE_REQ));
	LJV7IF_STORAGE_INFO *pInfo = (LJV7IF_STORAGE_INFO*)malloc(sizeof(LJV7IF_STORAGE_INFO));
	LJV7IF_GET_STORAGE_RSP *pRes = (LJV7IF_GET_STORAGE_RSP*)malloc(sizeof(LJV7IF_GET_STORAGE_RSP));



	pReq->dwSurface = 0;
	pReq->dwStartNo = 0;
	pReq->dwDataCnt = 8000;



	DWORD dwDataSize = sizeof(LJV7IF_MEASURE_DATA) * 8000;
	DWORD *pdwData = (DWORD*)malloc(dwDataSize);

	LJV7IF_GetStorageData(0, pReq, pInfo, pRes, pdwData, dwDataSize );

	LJV7IF_MEASURE_DATA *pData = (LJV7IF_MEASURE_DATA *)pdwData;
	for(int i=0; i<200; ++i)
	{
		for(int j=0; j<40; ++j)
		{
			of << pData->fValue << '\t';
			pData++;
		}
		of << endl;
	}
}
