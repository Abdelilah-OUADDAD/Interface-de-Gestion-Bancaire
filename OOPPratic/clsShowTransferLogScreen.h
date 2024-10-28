#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"

using namespace std;

class clsShowTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransferLogRecordLine(clsBankClient::stTransferLog Transfer) {
        cout << setw(8) << left << "" << "| " << left << setw(23) << Transfer.DateTime;
        cout << "| " << left << setw(8) << Transfer.sAcct;
        cout << "| " << left << setw(8) << Transfer.dAcct;
        cout << "| " << left << setw(8) << Transfer.Amount;
        cout << "| " << left << setw(10) << Transfer.sBalance;
        cout << "| " << left << setw(10) << Transfer.dBalance;
        cout << "| " << left << setw(10) << Transfer.User;
    }
    
    
public:
    static void ShowTransferLogListsScreen() {

        vector<clsBankClient::stTransferLog> vLogTransfer = clsBankClient::GetTransferLog();
        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t(" + to_string(vLogTransfer.size()) + ") Record(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(23) << left << "Date/Time";
        cout << "| " << setw(8) << left << "S.Acct";
        cout << "| " << setw(8) << left << "D.Acct";
        cout << "| " << setw(8) << left << "Amount";
        cout << "| " << setw(10) << left << "S.Balance";
        cout << "| " << setw(10) << left << "D.Balance";
        cout << "| " << setw(10) << left << "User";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";

        if (vLogTransfer.size() == 0) {
            cout << "\t\t\t\tNo Transfer Log Available in the System";
        }
        else {
            for (clsBankClient::stTransferLog c : vLogTransfer) {
                _PrintTransferLogRecordLine(c);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n";

    }
};

