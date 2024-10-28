#pragma once
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsCurrency.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

    static void _ShowResult(clsCurrency Currency) {
        
        if (!Currency.IsEmpty())
        {
            cout << "\nCurrency Found : -)\n";
            _PrintCurrency(Currency);
        }
        else
        {
           
            cout << "\nCurrency Is Not Found!\n";
        }
    }

public:

    static void ShowFindCurrencyScreen() {
        _DrawScreenHeader("\tFind Currency Sceen");

        short Num =1 ;

        cout << "\nFind By: [1] Code or [2] Country ? ";
        cin >> Num;
        if (Num == 1) {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputeValidate::ReadString();
            clsCurrency Currency1 = Currency1.FindByCode(CurrencyCode);
            _ShowResult(Currency1);
           
        }
        else {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputeValidate::ReadString();
            clsCurrency Currency2 = Currency2.FindByCountry(Country);
            _ShowResult(Currency2);
            
        }
    }
};

