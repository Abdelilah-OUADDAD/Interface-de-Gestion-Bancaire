#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsBankClient.h"
#include "clsScreen.h"
#include <iomanip>
#include<string>
#include "Global.h"

using namespace std;

class clsListClientScreen : protected clsScreen
{
private:
    static void _PrintClientRecordLine(clsBankClient Client) {
        cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
        cout << "| " << left << setw(20) << Client.FullName();
        cout << "| " << left << setw(12) << Client.Phone;
        cout << "| " << left << setw(20) << Client.Email;
        cout << "| " << left << setw(10) << Client.PinCode;
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

public:
    static void ShowClientListsScreen() {
       
        if (!CheckAccessRights(clsUser::enPermissions::pListUsers)) {
            return;
        }
        vector<clsBankClient> vClient = clsBankClient::GetClientList();
        string Title = "\tClient List";
        string SubTitle = "\t(" + to_string(vClient.size()) + ") Client(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout<<setw(8)<<left<<"" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(15) << left << "Account Number";
        cout << "| " << setw(20) << left << "Client Name";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(20) << left << "Email";
        cout << "| " << setw(10) << left << "Pin Code";
        cout << "| " << setw(12) << left << "Balance";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";

        if (vClient.size() == 0) {
            cout << "\t\t\t\tNo Client Available in the System";
        }
        else {
            for (clsBankClient& c : vClient) {
                _PrintClientRecordLine(c);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n";

    }
};

