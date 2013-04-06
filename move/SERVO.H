// SERVO.h : main header file for the SERVO application
//

#if !defined(AFX_SERVO_H__9F819BE5_8E96_11D4_8707_9D7D7EA60644__INCLUDED_)
#define AFX_SERVO_H__9F819BE5_8E96_11D4_8707_9D7D7EA60644__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "resrc1.h"

/////////////////////////////////////////////////////////////////////////////
// CSERVOApp:
// See SERVO.cpp for the implementation of this class
//

class CSERVOApp : public CWinApp
{
public:
	CSERVOApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSERVOApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSERVOApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVO_H__9F819BE5_8E96_11D4_8707_9D7D7EA60644__INCLUDED_)
