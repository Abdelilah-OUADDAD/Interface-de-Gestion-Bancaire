#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>

using namespace std; 

class clsLoginRegisterScreen : protected clsScreen
{
private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegister Login) {
		cout << setw(8) << left << "" <<"| "   << left << setw(30) <<  Login.DateTime;
		cout << "| " << left << setw(20) << Login.UserName;
		cout << "| " << left << setw(20) << Login.Password;
		cout << "| " << left << setw(12)  << Login.Permissions;
	}

public:

	static void ShowLoginRegisterScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) {
			return;
		}
		vector<clsUser::stLoginRegister> vLogin = clsUser::GetLoginRegisterList();
		string Title = "\tLogin Register List Screen";
		string Subtitle = "\t\t		(" + to_string(vLogin.size()) + ") Record(s). ";
		_DrawScreenHeader(Title, Subtitle);
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_____________________________________\n\n";
		cout << setw(8) << left << "" << "| " << setw(30) << left << "Date/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_____________________________________\n\n";

		if (vLogin.size() == 0) {
			cout << "\t\t\t\tNo Logins Available In the System!";
		}

		for (clsUser::stLoginRegister &c : vLogin) {
			_PrintLoginRegisterRecordLine(c);
			cout << endl;
		}
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_____________________________________\n\n";
	}

};

