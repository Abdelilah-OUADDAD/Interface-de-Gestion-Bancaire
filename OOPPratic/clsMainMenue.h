#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsDate.h"
#include "clsBankClient.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsListClientScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersMenue.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainMenue : protected clsScreen
{

private:

	enum enMainMenueOption {
		enShowClientList = 1, enAddNewClient = 2, enDeleteClient = 3
		, enUpdateClient = 4, enFindClient = 5, enTransaction = 6,
		enManageUsres = 7, enLoginRegister = 8, enCurrencyExchange = 9, enExit=10
	};

	static short _ReadMainMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]: ";
		short Num = clsInputeValidate::ReadShortNumberBetween(1,10,"Enter Number Between 1 to 10: ");
		return Num;
	}

	static void _ShowAllClientListScreen() {
		/*cout << "\nClient List will be here ...";*/
		clsListClientScreen::ShowClientListsScreen();
	}

	static void _ShowAddNewClientScreen() {
		/*cout << "\nAdd New Client will be here ...";*/
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {
		/*cout << "\nDelete Client will be here ...";*/
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {
		/*cout << "\nUpdate Client will be here ...";*/
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {
		/*cout << "\nFind Client will be here ...";*/
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionScreen() {
		/*cout << "\nTransaction will be here ...";*/
		clsTransactionScreen::ShowTransacrionMenue();
	}

	static void _ShowManageUserScreen() {
		/*cout << "\nManage User will be here ...";*/
		clsManageUsersMenue::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen() {
		/*cout << "\nLogin Register will be here ...";*/
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeScreen() {
		/*cout << "\nCurrency Exchange will be here ...";*/
		clsCurrencyExchangeScreen::ShowCurrencyMenue();
	}

	static void _Logout() {
		/*cout << "\nLogOut will be here ...";*/
		CurrentUser = clsUser::Find("","");
	}

	static void _GoBackToMainMenue() {
		cout << "\nPress Any Key To Go Back Main Menue...";
		system("pause>0");
		ShowMainMenue();
	}

	static void _PerformanceMainMenue(enMainMenueOption PerformanceOption) {

		switch (PerformanceOption)
		{
		case clsMainMenue::enShowClientList:
			system("cls");
			_ShowAllClientListScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enTransaction:
			system("cls");
			_ShowTransactionScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enManageUsres:
			system("cls");
			_ShowManageUserScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		case clsMainMenue::enExit:
			system("cls");
			_Logout();
			break;
		
		}
	}

public:

	static void ShowMainMenue() {
		system("cls");
		_DrawScreenHeader("\tMain Menue");
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t		Main Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "================================================\n";
		_PerformanceMainMenue((enMainMenueOption)_ReadMainMenue());
		
	}

};

