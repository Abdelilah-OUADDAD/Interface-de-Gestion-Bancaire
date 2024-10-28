#pragma once
#include <iostream>
#include "clsInputeValidate.h"
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsListUsersScreen.h"

using namespace std;


class clsAddNewUsersScreen : protected clsScreen
{
private:

   

    static int _ReadPermissions() {
        int Permission = 0;

        cout << "\nDo you want to give full access? y/n? ";
        char Answer;
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            return -1;
        }
        else {
            cout << "\nDo you want to give access to? \n";

            cout << "\nShow Client List? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pListUsers;
            }

            cout << "\nAdd New Client List? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pAddNewUsers;
            }

            cout << "\nDelete Client List? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pDeleteUsers;
            }

            cout << "\nUpdate Client List? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pUpdateUsers;
            }

            cout << "\nFindClient List? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pFindUsers;
            }

            cout << "\nTransaction? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pTransaction;
            }

            cout << "\nManage Users? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pManageUsers;
            }

            cout << "\nLogin Register? y/n? ";
            cin >> Answer;
            if (toupper(Answer) == 'Y') {
                Permission += clsUser::enPermissions::pLoginRegister;
            }
        }
        return Permission;
    }

    static void _ReadUserInfo(clsUser& user) {

        cout << "\nEnter First Name: ";
        user.FirstName = clsInputeValidate::ReadString();
        cout << "\nEnter Last Name: ";
        user.LastName = clsInputeValidate::ReadString();
        cout << "\nEnter Email: ";
        user.Email = clsInputeValidate::ReadString();
        cout << "\nEnter Phone: ";
        user.Phone = clsInputeValidate::ReadString();
        cout << "\nEnter Password: ";
        user.Password = clsInputeValidate::ReadString();
        cout << "\nEnter Permissions: ";
        user.Permissions = _ReadPermissions();

    }

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
    static void ShowAddNewUsersScreen() {

        _DrawScreenHeader("\tAdd New User Screen");
        string UserName;
        cout << "\nPlease Enter User Name: ";
        UserName = clsInputeValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name is not found , Enter again: ";
            UserName = clsInputeValidate::ReadString();
        }

        clsUser AddNewUser = clsUser::GetAddNewUserObject(UserName);



        cout << "\nAdd New User:\n";
        cout << "________________________________\n";

        _ReadUserInfo(AddNewUser);

        clsUser::enSaveResult SaveResult;

        SaveResult = AddNewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResult::svFailedEmptyObject:
            cout << "\nError User was not saved because it's Empty";
            break;
        case clsUser::enSaveResult::svSuccessed:
            cout << "\nUser Add Successfully!\n";
            _Print(AddNewUser);
            break;
        case clsUser::enSaveResult::svFaildAccountNumberExist:
        {
            cout << "\nError account was not saved because User is used!\n";
            break;

        }

        }
    }
};

