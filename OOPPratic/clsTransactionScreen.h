#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsShowTransferLogScreen.h"

using namespace std;

class clsTransactionScreen :protected clsScreen
{
private:

	enum enTransactionOption {
		eDeposit = 1, eWithRaw = 2, eTotalBalance = 3,
		eTransfer = 4, eShowTransferLog = 5,eMainMenue = 6
	};

	static short _ReadTransacrionMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		short Num = clsInputeValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6: ");
		return Num;
	}

	static void _ShowDeposit() {
		/*cout << "\nDeposit will be here ...";*/
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithraw() {
		/*cout << "\nWithraw will be here ...";*/
		clsWithrawScreen::ShowWithrawScreen();
	}

	static void _ShowTotalBalance() {
		/*cout << "\nTotalBalance will be here ...";*/
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransfer() {
		/*cout << "\nTransfer will be here ...";*/
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen() {
		/*cout << "\nShow Transfer Log will be here ...";*/
		clsShowTransferLogScreen::ShowTransferLogListsScreen();
	}

	static void _GoBackToTransactionMenue() {
		cout << "\nPress Any Key To Go Back Transaction Menue...";
		system("pause>0");
		ShowTransacrionMenue();
	}

	static void _PerformanceTransaction(enTransactionOption PerformanceOption) {
		
		switch (PerformanceOption)
		{
		case clsTransactionScreen::eDeposit:
			system("cls");
			_ShowDeposit();
			_GoBackToTransactionMenue();
			break;
		case clsTransactionScreen::eWithRaw:
			system("cls");
			_ShowWithraw();
			_GoBackToTransactionMenue();
			break;
		case clsTransactionScreen::eTotalBalance:
			system("cls");
			_ShowTotalBalance();
			_GoBackToTransactionMenue();
			break;
		case clsTransactionScreen::eTransfer:
			system("cls");
			_ShowTransfer();
			_GoBackToTransactionMenue();
			break;
		case clsTransactionScreen::eShowTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		case clsTransactionScreen::eMainMenue:
			break;
		}
	}
public:
	static void ShowTransacrionMenue() {
		if (!CheckAccessRights(clsUser::enPermissions::pTransaction)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransaction Menue");
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t		Transaction Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balance.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log List.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "================================================\n";
		_PerformanceTransaction((enTransactionOption)_ReadTransacrionMenue());
	}
};

