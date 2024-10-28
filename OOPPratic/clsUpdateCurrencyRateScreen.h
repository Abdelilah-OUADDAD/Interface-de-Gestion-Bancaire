#pragma once
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsCurrency.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
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

    static float _ReadRate() {
        float Rate;
        cout << "\nEnter New Rate: ";
        Rate = clsInputeValidate::ReadFloat();
        return Rate;
    }

public:

    static void ShowUpdateCurrencyRateScreen() {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode;
        cout << "\nPlease Enter CurrencyCode: ";
        CurrencyCode = clsInputeValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputeValidate::ReadString(); 
        }

        clsCurrency Currency = Currency.FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
        cin >> Answer;

        if (toupper(Answer)=='Y') {
            cout << "\nUpdate Currency Rate:";
            cout << "\n__________________________";
            
            Currency.UpdateRate(_ReadRate());
            cout << "\nCurrency Rate Update Successfully: -)";
            _PrintCurrency(Currency);
        }

    }
};

