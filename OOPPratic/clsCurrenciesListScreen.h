#pragma once
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsCurrency.h"
using namespace std;
class clsCurrenciesListScreen : protected clsScreen
{
private:
    static void _PrintCurrenciesRecordLine(clsCurrency Currencie) {
        cout << setw(8) << left << "" << "| " << left << setw(35) << Currencie.Country();
        cout << "| " << left << setw(9) << Currencie.CurrencyCode();
        cout << "| " << left << setw(40) << Currencie.CurrencyName();
        cout << "| " << left << setw(9) << Currencie.Rate();
    }

public:

    static void ShowCurrenciesListsScreen() {

        vector<clsCurrency> vCurrencie = clsCurrency::GetCurrenciesList();
        string Title = "\tCurrencies List Screen";
        string SubTitle = "\t(" + to_string(vCurrencie.size()) + ") Currency";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(35) << left << "Country";
        cout << "| " << setw(9) << left << "Code";
        cout << "| " << setw(40) << left << "Name";
        cout << "| " << setw(9) << left << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";

        if (vCurrencie.size() == 0) {
            cout << "\t\t\t\tNo Currencies Available in the System";
        }
        else {
            for (clsCurrency& c : vCurrencie) {
                _PrintCurrenciesRecordLine(c);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n";

    }
};

