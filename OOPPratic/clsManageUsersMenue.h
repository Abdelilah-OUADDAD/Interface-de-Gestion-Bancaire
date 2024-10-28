#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUsersScreen.h"
#include "clsDeleteUsersScreen.h"
#include "clsUpdateUsersScreen.h"
#include "clsFindUsersScreen.h"

using namespace std;

class clsManageUsersMenue : protected clsScreen
{
private:

	enum enManageUsers{eListUsers = 1, eAddNewUsers = 2, eDeleteUsers = 3, eUpdateUsers = 4, eFindUsers = 5, eMainMenue = 6};

	static short _ReadManageUsersMenue() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]: ";
		short Num = clsInputeValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 to 6: ");
		return Num;
	}

	static void _GoBackToManageUsersMenue() {
		cout << "\nPress Any Key To Go Back Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsers() {
		/*cout << "\tList Users will be here...";*/
		clsListUsersScreen::ShowUsersListsScreen();
	}

	static void _ShowAddNewUsers() {
		/*cout << "\tAdd New Users will be here...";*/
		clsAddNewUsersScreen::ShowAddNewUsersScreen();
	}

	static void _ShowDeleteUsers() {
		/*cout << "\tDelete Users will be here...";*/
		clsDeleteUsersScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUsers() {
		/*cout << "\tUpdate Users will be here...";*/
		clsUpdateUsersScreen::ShowUpdateUsersScreen();
	}

	static void _ShowFindUsers() {
		//cout << "\tFind Users will be here...";
		clsFindUsersScreen::ShowFindUserScreen();
	}
	
	static void _PerformanceManageUsers(enManageUsers PerformanceOption) {

		switch (PerformanceOption)
		{
		case clsManageUsersMenue::eListUsers:
			system("cls");
			_ShowListUsers(); 
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersMenue::eAddNewUsers:
			system("cls");
			_ShowAddNewUsers();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersMenue::eDeleteUsers:
			system("cls"); 
			_ShowDeleteUsers();
			_GoBackToManageUsersMenue(); 
			break;
		case clsManageUsersMenue::eUpdateUsers:
			system("cls");
			_ShowUpdateUsers();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersMenue::eFindUsers:
			system("cls");
			_ShowFindUsers();
			_GoBackToManageUsersMenue();
			break;
		case clsManageUsersMenue::eMainMenue:
			break;
		
		}
	}

public:

	static void ShowManageUsersMenue() {
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
			return;
		}
		system("cls");
		_DrawScreenHeader("\tManage Users Menue");
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t		Manage Users Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "================================================\n";
		_PerformanceManageUsers((enManageUsers)_ReadManageUsersMenue());
	}
};

