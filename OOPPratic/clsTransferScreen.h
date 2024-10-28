#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;
class clsTransferScreen : protected clsScreen
{

private:

	static void _Print(clsBankClient Client) {
		cout << "\nClient Card\n";
		cout << "___________________________\n";
		cout << "Full Name  : " << Client.FullName() << "\n";
		cout << "Acc.Number : " << Client.AccountNumber() << "\n";
		cout << "Balance	: " << Client.AccountBalance << "\n";
		cout << "___________________________\n\n";

	}

	static string ReadAccountNumber(string txt) {
		string AccountNumber;
		cout << txt;
		AccountNumber = clsInputeValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout<<"" << txt;
			AccountNumber = clsInputeValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient ClientFrom) {
		double Amount;
		cout << "\nEnter Transfer Amount? ";
		Amount = clsInputeValidate::ReadDblNumber();

		while (ClientFrom.AccountBalance < Amount) {
			cout << "\nAmount Execeeds the available Balance , Enter another Amount ? ";
			Amount = clsInputeValidate::ReadDblNumber();
		}
		return Amount;
	}
public:

	static void ShowTransferScreen() {

		_DrawScreenHeader("\tTransfer Screen");

		string AccountNumberFrom = ReadAccountNumber("\nPlease Enter Account Number to transfer From: ");
		clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);
		_Print(ClientFrom);

		string AccountNumberTo = ReadAccountNumber("\nPlease Enter Account Number to transfer To: ");
		clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
		_Print(ClientTo);

		double Amount = _ReadAmount(ClientFrom);
		

		char Answer = 'n';
		cout << "\nAre you sure do you want to perform this operation? y/n ? ";
		cin >> Answer;
		if(toupper(Answer) == 'Y')
		{
			if(ClientFrom.Transfer(Amount,ClientTo,CurrentUser.UserName)){
				cout << "\nTransfer Done Successfully";
			}
			else {
				cout << "\nTransfer failed \n";
			}

		}
		else
		{
			cout << "\nTransfer Operation Canceled";
		}
		_Print(ClientFrom);
		_Print(ClientTo);
		
	}

};

