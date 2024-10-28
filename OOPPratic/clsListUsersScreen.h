#pragma once

#include <iostream>
#include "clsUtil.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>
#include<string>

using namespace std;
class clsListUsersScreen : protected clsScreen
{
private:
    static void _PrintUsersRecordLine(clsUser User) {
        cout << setw(8) << left << "" << "| " << left << setw(12) << User.UserName;
        cout << "| " << left << setw(25) << User.FullName();
        cout << "| " << left << setw(12) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(10) << User.Password;
        cout << "| " << left << setw(12) << User.Permissions;
    }

public:

    static void ShowUsersListsScreen() {

        vector<clsUser> vUser = clsUser::GetUserList();
        string Title = "\tUser List";
        string SubTitle = "\t(" + to_string(vUser.size()) + ") User(s)";
        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";
        cout << setw(8) << left << "" << "| " << setw(12) << left << "User Name";
        cout << "| " << setw(25) << left << "Full Name";
        cout << "| " << setw(12) << left << "Phone";
        cout << "| " << setw(20) << left << "Email";
        cout << "| " << setw(10) << left << "Password";
        cout << "| " << setw(12) << left << "Permissions";
        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n\n";

        if (vUser.size() == 0) {
            cout << "\t\t\t\tNo Users Available in the System";
        }
        else {
            for (clsUser& c : vUser) {
                _PrintUsersRecordLine(c);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
        cout << "_____________________________________\n";

    }
};

