/*
**  Copyright (C) 2005-2006 Ingres Corporation. All Rights Reserved.
*/

/*
**    Source   : xsqlview.h : header file
**    Project  : SQL/Test (stand alone)
**    Author   : Sotheavut UK (uk$so01)
**    Purpose  : interface of the CvSqlQuery class
**
** History:
**
** 18-Fev-2002 (uk$so01)
**    Created
**    SIR #106648, Integrate SQL Test ActiveX Control
** 15-Oct-2003 (uk$so01)
**    SIR #106648, (Integrate 2.65 features for EDBC)
*/


#if !defined(AFX_XSQLVIEW_H__1D04F61C_EFC9_11D5_8795_00C04F1F754A__INCLUDED_)
#define AFX_XSQLVIEW_H__1D04F61C_EFC9_11D5_8795_00C04F1F754A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CdSqlQuery;
#include "axsql.h"
#include "axsqledb.h"

class CuSqlQueryControl: public 
#if defined (EDBC)
	CuSqlqueryEdbc
#else
	CuSqlquery
#endif
{
public:
#if defined (EDBC)
	CuSqlQueryControl(): CuSqlqueryEdbc(){}
#else
	CuSqlQueryControl(): CuSqlquery(){}
#endif

	~CuSqlQueryControl(){}

};


class CvSqlQuery : public CView
{
protected: // create from serialization only
	CvSqlQuery();
	DECLARE_DYNCREATE(CvSqlQuery)

public:
	CdSqlQuery* GetDocument();

	// Operations
public:

	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CvSqlQuery)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

	// Implementation
public:
	virtual ~CvSqlQuery();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	CuSqlQueryControl m_SqlQuery;

protected:

	// Generated message map functions
protected:
	//{{AFX_MSG(CvSqlQuery)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnPropertyChange();
	DECLARE_EVENTSINK_MAP()
};

#ifndef _DEBUG  // debug version in xsqlview.cpp
inline CdSqlQuery* CvSqlQuery::GetDocument()
	{ return (CdSqlQuery*)m_pDocument; }
#endif

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XSQLVIEW_H__1D04F61C_EFC9_11D5_8795_00C04F1F754A__INCLUDED_)
