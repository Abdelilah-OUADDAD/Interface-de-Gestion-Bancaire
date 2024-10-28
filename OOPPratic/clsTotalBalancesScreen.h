#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include "clsBankClient.h"
#include "clsMainMenue.h"
#include<string>
#include <iomanip>
#include "clsScreen.h"


using namespace std;
class clsTotalBalancesScreen : protected clsScreen
{
private:
    static void _PrintClientRecordBalancesLine(clsBankClient Client) {
        cout << setw(25) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }
public:

    static void ShowTotalBalances() {
        vector<clsBankClient> vClient = clsBankClient::GetClientList();
       
        string Titre = "Balances List Screen";
        string Subtitle = "\t(" + to_string(vClient.size()) + ") Client(s).";
        _DrawScreenHeader(Titre,Subtitle);
        cout << setw(25) << left << "" << "\n\t\t__________________________________________________________";
        cout << "___________________________\n" << endl;
        cout << setw(25) << left << "" << "| " << setw(15) << left << "Account Number";
        cout << "| " << setw(40) << left << "Client Name";
        cout << "| " << setw(12) << left << "Balance";
        cout << setw(25) << left << "" << "\t\t__________________________________________________________";
        cout << "___________________________\n" << endl;
        double TotaleBalances = clsBankClient::GetTotalBlances();
        if (vClient.size() == 0) {
            cout << "\t\t\t\tNo Client Available in the System";
        }
        else {
            for (clsBankClient& c : vClient) {
                _PrintClientRecordBalancesLine(c);
                cout << endl;
            }
        }

        cout << setw(25) << left << "" << "\n\t\t__________________________________________________________________";
        cout << "___________________________\n";

        cout << setw(8) << left << "" << "\t\t\t\t\tTotal Balances = " << TotaleBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t\t(" << clsUtil::NumberToText(TotaleBalances) << ")";
    }

};

