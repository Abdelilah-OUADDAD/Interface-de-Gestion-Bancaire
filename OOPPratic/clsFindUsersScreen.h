#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsListUsersScreen.h"

using namespace std;
class clsFindUsersScreen : clsScreen
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

    static void ShowFindUserScreen() {

        _DrawScreenHeader("\tFind User Screen");
        string UseName;
        cout << "\nPlease Enter User Name: ";
        UseName = clsInputeValidate::ReadString();
        while (!clsUser::IsUserExist(UseName))
        {
            cout << "\nUser Name is not found , Enter again: ";
            UseName = clsInputeValidate::ReadString();
        }

        clsUser user = clsUser::Find(UseName);
        if (!user.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser was not Found :-(\n";
        }

        _Print(user);

    }
};

