#pragma once
#include <iostream>
#include "clsUtil.h"
#include "clsInputeValidate.h"
#include "clsDate.h"
#include "clsBankClient.h"
#include <iomanip>
#include<string>
#include "clsScreen.h" 

using namespace std;

class clsAddNewClientScreen :protected clsScreen
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
    static void ShowAddNewClientScreen() {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewUsers)) {
            return;
        }
        _DrawScreenHeader("\tAdd New Client Screen");
        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found , Enter again: ";
            AccountNumber = clsInputeValidate::ReadString();
        }

        clsBankClient AddNewClient = clsBankClient::GetAddNewClientObject(AccountNumber);



        cout << "\nAdd New Client:\n";
        cout << "________________________________\n";

        _ReadClientInfo(AddNewClient);

        clsBankClient::enSaveResult SaveResult;

        SaveResult = AddNewClient.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFailedEmptyObject:
            cout << "\nError Account was not saved because it's Empty";
            break;
        case clsBankClient::enSaveResult::svSuccessed:
            cout << "\nAccount Add Successfully!\n";
            _Print(AddNewClient);
            break;
        case clsBankClient::enSaveResult::svFaildAccountNumberExist:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }

        }
    }

};

