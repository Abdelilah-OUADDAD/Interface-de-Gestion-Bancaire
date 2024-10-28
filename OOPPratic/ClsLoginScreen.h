#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsUser.h"
#include "clsInputeValidate.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsMainMenue.h"

using namespace std;
class ClsLoginScreen : protected clsScreen
{

private:

	static bool _Login() {
		bool LoginFaild = false;
		string UserName, Password;
		short FaildLoginCount = 0;
		do
		{
			if (LoginFaild) {

				FaildLoginCount++;
				cout << "\nInvalid UserName/Password!";
				cout << "\nYou have " << (3-FaildLoginCount) << " Trial(s) to login.\n\n";
				
			}
			
			if (FaildLoginCount == 3) {
				cout << "\nYou are loocked after 3 faild trails.\n\n";
				return false;
			}

			cout << "\nEnter User Name? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName,Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogin();
		clsMainMenue::ShowMainMenue();
	}
public:

	static bool ShowLoginScreen() {
		
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		return _Login();
	}
};

