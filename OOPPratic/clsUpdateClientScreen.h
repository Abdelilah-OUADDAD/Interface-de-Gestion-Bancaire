#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsDate.h"
#include "clsBankClient.h"
#include "clsMainMenue.h"
#include <iomanip>
#include<string>

using namespace std;
class clsUpdateClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Clients) {

        cout << "\nEnter First Name: ";
        Clients.FirstName = clsInputeValidate::ReadString();
        cout << "\nEnter Last Name: ";
        Clients.LastName = clsInputeValidate::ReadString();
        cout << "\nEnter Email: ";
        Clients.Email = clsInputeValidate::ReadString();
        cout << "\nEnter Phone: ";
        Clients.Phone = clsInputeValidate::ReadString();
        cout << "\nEnter Pin Code: ";
        Clients.PinCode = clsInputeValidate::ReadString();
        cout << "\nEnter Account Balanc: ";
        Clients.AccountBalance = clsInputeValidate::ReadFloat();


    }

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

    static void ShowUpdateClientScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateUsers)) {
          return;
        }
        _DrawScreenHeader("\tUpdate Client Screen");
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

        cout << "\nAre you sure you want to update this client y/n?";
        char Answer = 'n';
        cin >> Answer;
        if (toupper(Answer)=='Y') {

            cout << "\n\nUpdate Client:";
            cout << "\n________________________";
            _ReadClientInfo(client);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = client.Save();

            switch (SaveResult)
            {
            case clsBankClient::svFailedEmptyObject:
            {
                cout << "\nError Account was not saved because it's Empty";
                break;
            }
            case clsBankClient::svSuccessed:
            {
                cout << "\nAccount Update Successfully!\n";
                _Print(client);
                break;
            }

            }
        }
    }
};

