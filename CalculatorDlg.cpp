
// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalculatorDlg dialog




CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCalculatorDlg::IDD, pParent)
	, m_DisplayResult(_T(""))
	, m_DisplayHistory(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON_NumberZero, m_numberZero);
	DDX_Control(pDX, IDC_BUTTON_NumberOne, m_numberOne);
	DDX_Control(pDX, IDC_BUTTON_NumberTwo, m_numberTwo);
	DDX_Control(pDX, IDC_BUTTON_NumberThree, m_numberThree);
	DDX_Control(pDX, IDC_BUTTON_NumberFour, m_numberFour);
	DDX_Control(pDX, IDC_BUTTON_NumberFive, m_numberFive);
	DDX_Control(pDX, IDC_BUTTON_NumberSix, m_numberSix);
	DDX_Control(pDX, IDC_BUTTON_NumberSeven, m_numberSeven);
	DDX_Control(pDX, IDC_BUTTON_NumberEight, m_numberEight);
	DDX_Control(pDX, IDC_BUTTON_NumberNine, m_numberNine);

	DDX_Control(pDX, IDC_BUTTON_Plus, m_buttonPlus);
	DDX_Control(pDX, IDC_BUTTON_Minus, m_buttonMinus);
	DDX_Control(pDX, IDC_BUTTON_Multiply, m_buttonMultiply);
	DDX_Control(pDX, IDC_BUTTON_Divided, m_buttonDivided);
	DDX_Control(pDX, IDC_BUTTON_Equal, m_buttonEqual);
	DDX_Control(pDX, IDC_BUTTON_Clear, m_buttonClear);

	DDX_Text(pDX, IDC_EDIT1_DisplayResult, m_DisplayResult);
	DDX_Text(pDX, IDC_EDIT_DisplayHistory, m_DisplayHistory);
	DDX_Control(pDX, IDC_EDIT1_DisplayResult, m_EditOutput);
	DDX_Control(pDX, IDC_EDIT_DisplayHistory, m_EditHistory);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_BUTTON_NumberZero, &CCalculatorDlg::OnBnClickedButtonNumberzero)
	ON_BN_CLICKED(IDC_BUTTON_NumberOne, &CCalculatorDlg::OnBnClickedButtonNumberone)
	ON_BN_CLICKED(IDC_BUTTON_NumberTwo, &CCalculatorDlg::OnBnClickedButtonNumbertwo)
	ON_BN_CLICKED(IDC_BUTTON_NumberThree, &CCalculatorDlg::OnBnClickedButtonNumberthree)
	ON_BN_CLICKED(IDC_BUTTON_NumberFour, &CCalculatorDlg::OnBnClickedButtonNumberfour)
	ON_BN_CLICKED(IDC_BUTTON_NumberFive, &CCalculatorDlg::OnBnClickedButtonNumberfive)
	ON_BN_CLICKED(IDC_BUTTON_NumberSix, &CCalculatorDlg::OnBnClickedButtonNumbersix)
	ON_BN_CLICKED(IDC_BUTTON_NumberSeven, &CCalculatorDlg::OnBnClickedButtonNumberseven)
	ON_BN_CLICKED(IDC_BUTTON_NumberEight, &CCalculatorDlg::OnBnClickedButtonNumbereight)
	ON_BN_CLICKED(IDC_BUTTON_NumberNine, &CCalculatorDlg::OnBnClickedButtonNumbernine)


	ON_BN_CLICKED(IDC_BUTTON_Plus, &CCalculatorDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_Minus, &CCalculatorDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_Multiply, &CCalculatorDlg::OnBnClickedButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_Divided, &CCalculatorDlg::OnBnClickedButtonDivided)
	ON_BN_CLICKED(IDC_BUTTON_Clear, &CCalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_Equal, &CCalculatorDlg::OnBnClickedButtonEqual)
END_MESSAGE_MAP()


// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// setup the text font
	OutputFont.CreateFont(32,0,0,0,FW_BOLD, 0,0,0,DEFAULT_CHARSET,
			0,0,0,0,_T("Microsoft Sans Seri"));
	HistoryFont.CreateFont(16,0,0,0,FW_BOLD, 0,0,0,DEFAULT_CHARSET,
		0,0,0,0,_T("Microsoft Sans Seri"));

	m_EditOutput.SetFont(&OutputFont);
	m_EditHistory.SetFont(&HistoryFont);

	m_numberZero.SetFont(&OutputFont);
	m_numberOne.SetFont(&OutputFont);
	m_numberTwo.SetFont(&OutputFont);
	m_numberThree.SetFont(&OutputFont);
	m_numberFour.SetFont(&OutputFont);
	m_numberFive.SetFont(&OutputFont);
	m_numberSix.SetFont(&OutputFont);
	m_numberSeven.SetFont(&OutputFont);
	m_numberEight.SetFont(&OutputFont);
	m_numberNine.SetFont(&OutputFont);

	m_buttonPlus.SetFont(&OutputFont);
	m_buttonMinus.SetFont(&OutputFont);
	m_buttonMultiply.SetFont(&OutputFont);
	m_buttonDivided.SetFont(&OutputFont);
	m_buttonEqual.SetFont(&OutputFont);
	m_buttonClear.SetFont(&OutputFont);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
// The user defined function will write as below:
void CCalculatorDlg::reset()
{
	m_calculator.reset();
	m_error_Input = false;
	m_firstDigitEntered = FALSE;
	resetOutput();
	m_DisplayHistory = "";
	UpdateData(FALSE);
}

void CCalculatorDlg::resetOutput()
{	
	//original 
	//m_DisplayResult = m_DisplayResultResetString;
	m_DisplayResult = "0"; 
};

void CCalculatorDlg::AddDigit(char digit){
	//m_DisplayResult += digit;
	//UpdateData(FALSE);
	if(m_error_Input)
		return;
	if(m_calculator.isOperation(m_calculator.getLastInput().actionType) && !m_firstDigitEntered){
		m_DisplayResult = digit;
	}
	else{
		if(m_DisplayResult == "0" && digit == '0')
			return;
		else if (m_DisplayResult == "0"){
			m_DisplayResult = digit;
		}
		else
			m_DisplayResult = digit;
	}
	m_firstDigitEntered = TRUE;
	UpdateData(FALSE);
}

void CCalculatorDlg::OnBnClickedButtonNumberzero()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('0');

}

void CCalculatorDlg::OnBnClickedButtonNumberone()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('1');
}

void CCalculatorDlg::OnBnClickedButtonNumbertwo()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('2');
}

void CCalculatorDlg::OnBnClickedButtonNumberthree()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('3');
}

void CCalculatorDlg::OnBnClickedButtonNumberfour()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('4');
}

void CCalculatorDlg::OnBnClickedButtonNumberfive()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('5');
}

void CCalculatorDlg::OnBnClickedButtonNumbersix()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('6');
}

void CCalculatorDlg::OnBnClickedButtonNumberseven()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('7');
}

void CCalculatorDlg::OnBnClickedButtonNumbereight()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('8');
}

void CCalculatorDlg::OnBnClickedButtonNumbernine()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
	AddDigit('9');
}
// add the algorithm function (user define function) in this block

void CCalculatorDlg::createHistoryText()
{
	m_DisplayHistory = "";
	int historySize = m_calculator.getActionsSize();
	for(int i =0; i< historySize; i++){
		switch (m_calculator.getAction(i).actionType){
		case Calculator:: ActionType::Number:
			{
				CString strNumber;
				std::stringstream ss;
				ss<< m_calculator.getAction(i).value;
				std::string stdNum == ss.str();
				
				strNumber = stdNum.c_str();
				if(m_DisplayHistory.IsEmpty())
					m_DisplayHistory = strNumber;
				else
					m_DisplayHistory = (CString("")+strNumber);
			}
			break;
		case Calculator::ActionType::Plus:
			m_DisplayHistory += " +";
			break;
		case Calculator::ActionType::Minus:
			m_DisplayHistory += " -";
			break;
		case Calculator::ActionType::Multiply:
			m_DisplayHistory += " x";
			break;
		case Calculator::ActionType::Divide:
			m_DisplayHistory += " /";
			break;
		case Calculator::ActionType::Equals:
			m_DisplayHistory += " =";
			break;
		case Calculator::ActionType::None:
			break;
		}
	}
};

void CCalculatorDlg::dotOperation(Calculator::ActionType operation, bool handleNumber)
{
	if(m_error_Input)
		return;
	UpdateData();
	Calculator::Action input;
	if (handleNumber){

		input.actionType == Calculator::ActionType::Number;
		input.value == _wtof(m_DisplayResult);
		m_calculator.addInput(input);
	}
	input.actionType = operation;
	m_error_Input = false;
	try
	{
		// After a (valid) operation we always print a current result if
		// there is something to print currently. This is the case with all the current 
		// operations. Later on if there is different kind of operation which does not
		// behave like this, then a new code is needed here for that operation.
		if (m_calculator.addInput(input))
		{
			// The only situation we will not print the total result here is if both term and 
			// expression have values currently (are "in use"). For example: "3 + 5 /", 
			// => operation == Divide and we would not like to print the total result of
			// this yet becouse that would be 3; we want to wait until the term part (5 / ...)
			// is finished, then we will print the total 3 + ... .
			if (!m_calculator.hasLeftTermValue() || !m_calculator.hasLeftExpressionValue())
			{
				// print the current total value
				std::stringstream ss;
				ss << m_calculator.getCurrentResult();
				std::string curResult = ss.str();

				m_DisplayResult = "";
				m_DisplayResult += curResult.c_str();
				UpdateData(FALSE);
			}
		}
		else // this should never happen; coming here means possible an error in the code
			AfxMessageBox(_T("Error: An unknown operation.")); 
	}
	catch (std::exception& e)
	{
		// note: the user can only continue after "divided by zero" error
		// by pressing "C"/reset.
		m_DisplayResult = e.what();
		m_firstDigitEntered = FALSE;
		m_error_Input = true;
	}
	// update output
	createHistoryText();
	if (operation == Calculator::ActionType::Equals)
	{
		if (m_error_Input)
			m_DisplayHistory += " ";
		m_DisplayHistory += m_DisplayResult;
	}
	UpdateData(FALSE);
	m_firstDigitEntered = FALSE;
}
void CCalculatorDlg::OnBnClickedButtonPlus()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}


void CCalculatorDlg::OnBnClickedButtonMinus()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}


void CCalculatorDlg::OnBnClickedButtonMultiply()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}


void CCalculatorDlg::OnBnClickedButtonDivided()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}


void CCalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}


void CCalculatorDlg::OnBnClickedButtonEqual()
{
	// TODO: 北兜矪瞶盽Α祘Α絏
}
