#pragma once

#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsListUsersScreen.h"

using namespace std;

class clsDeleteUsersScreen: protected clsScreen
{
private:

    static void _Print(clsUser user) {
        cout << "\nUser Card:";
        cout << "\n________________________________\n";
        cout << "First Name: " << user.FirstName << endl;
        cout << "Last Name : " << user.LastName << endl;
        cout << "Full Name : " << user.FullName() << endl;
        cout << "Email     : " << user.Email << endl;
        cout << "Phone     : " << user.Phone << endl;
        cout << "User Name : " << user.UserName << endl;
        cout << "Password  : " << user.Password << endl;
        cout << "Pemissions: " << user.Permissions << endl;
        cout << "\n________________________________\n";
    }

public:

    static void ShowDeleteUserScreen() {

        _DrawScreenHeader("\tDelete User Screen");
        string UserName;
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputeValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found , Enter again: ";
            UserName = clsInputeValidate::ReadString();
        }

        clsUser user = clsUser::Find(UserName);
        _Print(user);

        char Answer = 'n';
        cout << "\nDo you want to delete User ? y/n? ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {

            if (user.Deleted()) {
                cout << "\nUser Deleted Successfully!!";
                _Print(user);
            }
            else
            {
                cout << "\nError Client was not Deleted\n";
            }
        }

    }

};

