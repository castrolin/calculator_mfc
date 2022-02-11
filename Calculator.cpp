
// Calculator.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorApp

BEGIN_MESSAGE_MAP(CCalculatorApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCalculatorApp construction

CCalculatorApp::CCalculatorApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CCalculatorApp object

CCalculatorApp theApp;


// CCalculatorApp initialization

BOOL CCalculatorApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	CCalculatorDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

//Setting 

//**********PROBLEM IN HERE****** ****

Calculator::sAction Calculator::getLastInput() const 
{	
	/*if( m_actions.size() <= 0){
		getLastInput().actionType == None;
		getLastInput().value == 0;
		return getLastInput();
	}
	else
		m_actions.back();*/

	if(m_actions.size() <= 0)
	{
		return Calculator::sAction (ActionType::None, 0.0);;
	}	

	return m_actions.back();
}
//***********************************


void Calculator::reset()
{
	m_leftExpression.reset();
	m_leftTerm.reset();
	m_actions.clear();
}

bool Calculator::isOperation(ActionType action) const
{
	return(action == ActionType::Plus || action == ActionType::Minus||
			action == ActionType::Multiply || action == ActionType::Divide||
			action == ActionType::Equals);
}

bool Calculator::isTerm(ActionType action) const
{
	return(action == ActionType::Multiply || action == ActionType::Divide);
}
bool Calculator::isExpression(ActionType action) const
{
	return(action == ActionType::Plus || action == ActionType::Minus);
}

ActionType Calculator::getLastOperation()
{
	for(auto op= m_actions.rbegin(); op!= m_actions.rend(); ++op){ // op mean is OPeration
		if(isOperation(op->m_actionType)){
			return op-> m_actionType;
		}
	}
	return ActionType::None;	
}

double Calculator::getCurrentResult() const
{
	return m_leftExpression.hasValue() ? m_leftExpression.getValue(): m_leftTerm.getValue();
}

bool Calculator::addInput(const Calculator::sAction& input)
{
	const Calculator::sAction lastInput = Calculator::getLastInput();

	if(input.m_actionType == ActionType::Number){
		if(lastInput.m_actionType != ActionType::Number){
			m_actions.push_back(input);
		}
	}
	else if (isOperation(input.m_actionType)){

		if(lastInput.m_actionType == ActionType::Number){

			ActionType lastOperation = getLastOperation();

			switch(lastOperation){

			case ActionType::Plus:
				if(isExpression(input.m_actionType) || input.m_actionType == ActionType::Equals){
					m_leftExpression.add(lastInput.m_dValue);
					m_leftTerm.reset();
				}
				else if (isTerm(input.m_actionType)){
					m_leftTerm.set(lastInput.m_dValue);
				}
				break;

			case ActionType::Minus:
				if(isExpression(input.m_actionType) || input.m_actionType == ActionType::Equals){
					m_leftExpression.add(-lastInput.m_dValue);
					m_leftTerm.reset();
				}
				else if (isTerm(input.m_actionType)){
					m_leftTerm.set(-lastInput.m_dValue);
				}
				break;
			case ActionType::Multiply:
				if(isExpression(input.m_actionType) || input.m_actionType == ActionType::Equals){
					m_leftExpression.add(m_leftTerm.getValue() * lastInput.m_dValue);
					m_leftTerm.reset();
				}
				else if (isTerm(input.m_actionType)){
					m_leftTerm.multiplyBy(lastInput.m_dValue);
				}
				break;
			case ActionType::Divide:

				if(isExpression(input.m_actionType) || input.m_actionType == ActionType::Equals){
					if (lastInput.m_dValue == 0.0){
						CalculatorException divByZeroException("Error: Cannot Divided by zero",
								CalculatorException::ExceptionType::DividedByZero);
						throw divByZeroException;
					}
					else{
						m_leftExpression.add(m_leftTerm.getValue() / lastInput.m_dValue);
						m_leftTerm.reset();
					}
					
				}
				else if (isTerm(input.m_actionType)){
					m_leftTerm.set(1.0/lastInput.m_dValue);
				}
				break;

			case ActionType::Equals:
				if(isTerm(input.m_actionType)){
					m_leftExpression.reset();
					m_leftTerm.set(lastInput.m_dValue);
				}
				else if (isExpression(input.m_actionType)){
					m_leftExpression.set(lastInput.m_dValue);
					m_leftTerm.reset();
				}
				break;

			case ActionType::None:
				if(isTerm(input.m_actionType)){
					m_leftExpression.reset();
					m_leftTerm.set(lastInput.m_dValue);
				}
				else if (isExpression(input.m_actionType)){
					m_leftExpression.set(lastInput.m_dValue);
					m_leftTerm.reset();
				}
				break;

			}
			m_actions.push_back(input);
			return true;
		}
	}
	return false;
}