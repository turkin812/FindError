
// Task1Dlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "Task1.h"
#include "Task1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CTask1Dlg



CTask1Dlg::CTask1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTask1Dlg::IDD, pParent)
	, TextEdit1(_T(""))
	//, TextEdit2(_T(""))
	, TextEdit2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTask1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, TextEdit1);
	//DDX_Text(pDX, IDC_ERROR_TEXT, TextEdit2);
	DDX_Text(pDX, IDC_ERROR_TEXT, TextEdit2);
}

BEGIN_MESSAGE_MAP(CTask1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CTask1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CTask1Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CTask1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CTask1Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTask1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ����������� ��������� CTask1Dlg

BOOL CTask1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CTask1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CTask1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTask1Dlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	//CDialogEx::OnOK();
}

//������ ������
void CTask1Dlg::OnBnClickedCancel()
{
	// TODO: �������� ���� ��� ����������� �����������
	
	//TextEdit2 = TextEdit1;
	//int codError = _tstoi(TextEdit1);
	int codError;
	swscanf_s(TextEdit1.GetString(), L"%i", &codError);
	//TextEdit2.Format(L"%i", aa);

	DWORD Error = codError;
	wchar_t *text;
	::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL, Error, 0, (LPTSTR)&text, 0, NULL);
	
	TextEdit2 = text;
	::LocalFree(text);

	UpdateData(FALSE);
	
}


void CTask1Dlg::OnEnChangeEdit1()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������

	UpdateData(FALSE);
}


void CTask1Dlg::OnEnChangeEdit2()
{
	// TODO:  ���� ��� ������� ���������� RICHEDIT, �� ������� ���������� �� �����
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  �������� ��� �������� ����������
	UpdateData(TRUE);
}


void CTask1Dlg::OnBnClickedButton3()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialogEx::OnOK();
}
