#pragma once
#include <iostream>
#include <iomanip>
#include<string>
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:

	static void _DrawScreenHeader(string Title,string SubTitle = "") 
	{
		cout  << "\t\t\t\t\t________________________________________________\n";
		cout  << "\n\t\t\t\t\t\t" << Title << endl;
		if (SubTitle != "") {
			cout << "\t\t\t\t\t\t" << SubTitle << endl;

		}
		cout << "\n\t\t\t\t\t________________________________________________\n";
		cout << "\n\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}
	
	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheeckPermission(Permission)) {
			cout << "\t\t\t\t\t___________________________________________________\n";
			cout << "\n\n\t\t\t\t\t\tAccess Denied! Contact your Admin. ";
			cout << "\n\t\t\t\t\t___________________________________________________\n";

			return false;
		}
		else {
			return true;
		}
	}
};

