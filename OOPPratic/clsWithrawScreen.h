#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include "clsBankClient.h"
#include "clsMainMenue.h"
#include<string>
#include "clsScreen.h"

using namespace std;
class clsWithrawScreen : protected clsScreen
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

    static string _ReadAccountNumber() {
        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputeValidate::ReadString();
        return AccountNumber;
    }
public:

    static void ShowWithrawScreen() {
        _DrawScreenHeader("\tWithraw Screen");
        string AccountNumber = _ReadAccountNumber();
       
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number is not found , Enter again: ";
            AccountNumber = _ReadAccountNumber();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _Print(client);

        cout << "\nPlease Enter deposit amount? ";
        double Amount = 0;
        Amount = clsInputeValidate::ReadDblNumber();

        char Answer = 'n';
        cout << "\nAre you sure you want to perform this transaction? y/n? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            if(client.Withraw(Amount)){
                cout << "\nAmount Withraw Successfully.\n";
                cout << "\nNew Balance Is: " << client.AccountBalance;
            }
            else {
                cout << "\nCannot withraw ,Insuffecient Balance!";
                cout << "\n\nAmount to withraw is : " <<  Amount;
                cout << "\nYour balance is: " << client.AccountBalance;
            }
        }
        else {
            cout << "\nOperation was cancelled";
        }
    }
};

