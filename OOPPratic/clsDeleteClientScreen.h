#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsBankClient.h"
#include "clsMainMenue.h"
#include <iomanip>
#include<string>

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _Print(clsBankClient client) {
        cout << "\nClient Card:";
        cout << "\n________________________________\n";
        cout << "First Name	: " << client.FirstName << endl;
        cout << "Last Name	: " << client.LastName << endl;
        cout << "Full Name	: " << client.FullName() << endl;
        cout << "Email		: " << client.Email << endl;
        cout << "Phone		: " << client.Phone << endl;
        cout << "Account Number  : " << client.AccountNumber() << endl;
        cout << "Pin Code	: " << client.PinCode << endl;
        cout << "Account Balance : " << client.AccountBalance << endl;
        cout << "\n________________________________\n";
    }
public:
    static void ShowDeleteClientScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteUsers)) {
            return;
        }
        _DrawScreenHeader("\tDelete Client Screen");
        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found , Enter again: ";
            AccountNumber = clsInputeValidate::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _Print(client);

        char Answer = 'n';
        cout << "\nDo you want to delete client ? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {

            if (client.Deleted()) {
                cout << "\nClient Deleted Successfully!!";
                _Print(client);
            }
            else
            {
                cout << "\nError Client was not Deleted\n";
            }
        }

    }
};

