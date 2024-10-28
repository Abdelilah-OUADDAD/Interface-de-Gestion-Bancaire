#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:

	struct stLoginRegister;
	enum enMode { EmptyMod = 0, UpdateMode = 1, AddNewMode = 2 };

	enMode _Mode;
	string _UserName;
	string _Password;
	int	_Permissions;

	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUsersObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUser = clsString::Split(Line, Seperator);
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4],clsUtil::DecryptText(vUser[5]), stof(vUser[6]));
	}

	static clsUser _GetEmptyUsersObject() {
		return clsUser(enMode::EmptyMod, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadingUsersDataToFile() {
		vector<clsUser> vUser;
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUsersObject(Line);
				vUser.push_back(User);
			}
			MyFile.close();
		}
		return vUser;
	}

	string _ConvertUsersObjectToLine(clsUser user, string Seperator = "#//#") {
		string s1 = "";
		s1 += user.FirstName + Seperator;
		s1 += user.LastName + Seperator;
		s1 += user.Email + Seperator;
		s1 += user.Phone + Seperator;
		s1 += user.UserName + Seperator;
		s1 += clsUtil::EncryptText( user.Password)+ Seperator;
		s1 += to_string(user.Permissions);
		return s1;
	}

	void _SaveUsersDataObject(vector<clsUser> vUser) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsUser& c : vUser)
			{
				if (c._MarkForDelete == false) {
					Line = _ConvertUsersObjectToLine(c);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector<clsUser> vUser = _LoadingUsersDataToFile();
		for (clsUser& c : vUser) {
			if (c.UserName == GetUserName()) {
				c = *this;
				break;
			}
		}

		_SaveUsersDataObject(vUser);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConvertUsersObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		
		if (MyFile.is_open())
		{

			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	string _PraparetoLogInRecord(string Seperator = "#//#") 
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	static stLoginRegister  _ConvertLoginRegisterLineRecord(string Line,string Seperator = "#//#") {
		vector<string> vLogin = clsString::Split(Line,Seperator);
		stLoginRegister Login;
		Login.DateTime = vLogin[0];
		Login.UserName = vLogin[1];
		Login.Password = clsUtil::DecryptText(vLogin[2]);
		Login.Permissions = stoi(vLogin[3]);
		return Login;
	}
	
public:

	struct stLoginRegister {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};
	enum enPermissions {
		pListUsers = 1, pAddNewUsers = 2, pDeleteUsers = 4, pUpdateUsers = 8, pFindUsers = 16,
		pTransaction = 32, pManageUsers = 64, pLoginRegister = 128, pAll = -1
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email,
		string Phone, string UserName, string Password, int Permissions) :
		clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	 bool CheeckPermission(enPermissions Permission) {
		if (this->Permissions == enPermissions::pAll) {
			return true;
		}
		
		if ((this->Permissions & Permission) == Permission) {
			return true;
		}
		return false;
		
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMod);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}

	void setUserName(string UserName) {
		_UserName = UserName;
	}

	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = setUserName)) string UserName;

	void setPassword(string PassWord) {
		_Password = PassWord;
	}

	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = setPassword)) string Password;

	void setPermissions(int Permissions) {
		_Permissions = Permissions;
	}

	int GetPermissions() {
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = setPermissions)) int Permissions;

	static clsUser Find(string UserName) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUsersObject(Line);

				if (User.GetUserName() == UserName) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUsersObject();
	}

	static clsUser Find(string UserName, string Password) {
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUsersObject(Line);

				if ((User.GetUserName() == UserName) && (User.GetPassword() == Password)) {
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUsersObject();
	}

	static bool IsUserExist(string UserName) {
		clsUser User = Find(UserName);
		return (!User.IsEmpty());
	}


	enum enSaveResult { svFailedEmptyObject = 0, svSuccessed = 1, svFaildAccountNumberExist };

	enSaveResult Save() {

		switch (_Mode)
		{
		case enMode::EmptyMod:
		{
			if (IsEmpty())
			{
				return enSaveResult::svFailedEmptyObject;

			}
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSuccessed;
			break;
		}
		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_UserName)) {
				return enSaveResult::svFaildAccountNumberExist;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSuccessed;
			}
		}

		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Deleted() {
		vector<clsUser> vUser = _LoadingUsersDataToFile();
		for (clsUser& c : vUser) {
			if (c.GetUserName() == GetUserName())
			{
				c._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataObject(vUser);

		*this = _GetEmptyUsersObject();

		return true;
	}

	static vector<clsUser> GetUserList() {
		return _LoadingUsersDataToFile();
	}

	void RegisterLogin()
	{
		 string DataLineLogin = _PraparetoLogInRecord();

		fstream MyFile;
		MyFile.open("LoginRegister.txt" , ios::out|ios::app);
		
		if (MyFile.is_open()) 
		{
			MyFile << DataLineLogin << endl;

			MyFile.close();
		}
	}

	static vector<stLoginRegister> GetLoginRegisterList()
	{
		
		vector<stLoginRegister> vLogin;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);
		
		if (MyFile.is_open())
		{
			string Line;
			stLoginRegister dataLogin;
			while (getline(MyFile,Line))
			{
				dataLogin = _ConvertLoginRegisterLineRecord(Line);
				vLogin.push_back(dataLogin);
			}

			MyFile.close();
		}
		return vLogin;
	}

};

