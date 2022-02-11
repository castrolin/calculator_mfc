
// CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CCalculatorDlg dialog
class CCalculatorDlg : public CDialogEx
{
// Construction
public:
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNumberzero();
	afx_msg void OnBnClickedButtonNumberone();
	afx_msg void OnBnClickedButtonNumbertwo();
	afx_msg void OnBnClickedButtonNumberthree();
	afx_msg void OnBnClickedButtonNumberfour();
	afx_msg void OnBnClickedButtonNumberfive();
	afx_msg void OnBnClickedButtonNumbersix();
	afx_msg void OnBnClickedButtonNumberseven();
	afx_msg void OnBnClickedButtonNumbereight();
	afx_msg void OnBnClickedButtonNumbernine();

	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMultiply();
	afx_msg void OnBnClickedButtonDivided();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonEqual();

private:
	//*****INITIALIZATION of VARIABLE ????********
	// user defined variable
	bool m_error_Input;
	BOOL m_firstDigitEntered;
	//const CString m_OutputResetString = {"0"};

	// user defined function
	void AddDigit(char digit);
	void reset();
	void resetOutput();
	void CCalculatorDlg::dotOperation(ActionType operation, bool handleNumber= true);
	void CCalculatorDlg:: createHistoryText();


	Calculator m_calculator;

	CFont OutputFont;
	CFont HistoryFont;

	CButton m_numberZero;
	CButton m_numberOne;
	CButton m_numberTwo;
	CButton m_numberThree;
	CButton m_numberFour;
	CButton m_numberFive;
	CButton m_numberSix;
	CButton m_numberSeven;
	CButton m_numberEight;
	CButton m_numberNine;
	CButton m_buttonPlus;
	CButton m_buttonMinus;
	CButton m_buttonMultiply;
	CButton m_buttonDivided;
	CButton m_buttonEqual;
	CButton m_buttonClear;


	CString m_DisplayResult;
	CString m_DisplayHistory;
	CString h;


	CEdit m_EditOutput;
	CEdit m_EditHistory;
};
