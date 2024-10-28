#pragma once
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatotScreen.h"

using namespace std;
class clsCurrencyExchangeScreen : protected clsScreen
{
private:

	enum enCurrencyMenueOption {
		enListCurrencie = 1, enFindCurrency = 2, enUpdateRate = 3
		, enCurrencyCalculator = 4, enMainMenue = 5
	};

	static short _ReadCurrencieMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]: ";
		short Num = clsInputeValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 to 5: ");
		return Num;
	}

	static void _GoBackToCurrencieMenue() {
		cout << "\nPress Any Key To Go Back Main Menue...";
		system("pause>0");
		ShowCurrencyMenue();
	}

	static void _ShowListCurrencie() {
		/*cout << "\nList Currency will be here";*/
		clsCurrenciesListScreen::ShowCurrenciesListsScreen(); 
	}

	static void _ShowFindCurrency() {
		/*cout << "\Find Currency will be here";*/
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRate() {
		//cout << "\nUpdateRate will be here";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCalculatorCurrencie() {
		/*cout << "\nCalculator Currencie will be here";*/
		clsCurrencyCalculatotScreen::ShowCurrencyCalculator();
	}

	static void PerformanceCurrencieMenue(enCurrencyMenueOption CurrencieOption) {

		switch (CurrencieOption)
		{
		case clsCurrencyExchangeScreen::enListCurrencie:
			system("cls");
			_ShowListCurrencie();
			_GoBackToCurrencieMenue();
			break;
		case clsCurrencyExchangeScreen::enFindCurrency:
			system("cls"); 
			_ShowFindCurrency();
			_GoBackToCurrencieMenue(); 
			break;
		case clsCurrencyExchangeScreen::enUpdateRate:
			system("cls");
			_ShowUpdateRate(); 
			_GoBackToCurrencieMenue();
			break;
		case clsCurrencyExchangeScreen::enCurrencyCalculator:
			system("cls");
			_ShowCalculatorCurrencie();
			_GoBackToCurrencieMenue();
			break;
		case clsCurrencyExchangeScreen::enMainMenue:
			break;
		default:
			break;
		}
	}

public:

	static void ShowCurrencyMenue() {
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Mene");
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t		Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "================================================\n";
		PerformanceCurrencieMenue((enCurrencyMenueOption)_ReadCurrencieMenue());

	}
};

