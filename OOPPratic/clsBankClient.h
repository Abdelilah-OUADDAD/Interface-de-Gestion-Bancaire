#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode{ EmptyMod = 0, UpdateMode = 1,AddNewMode = 2 };

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float  _AccountBalance;
	bool _MatchCase = false;
	struct stTransferLog;
	

	static clsBankClient _ConvertLineToClientObject(string Line ,string Seperator = "#//#")
	{
		vector<string> vClient = clsString::Split(Line, Seperator);
		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5],stof( vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMod, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadingClientDataToFile() {
		vector<clsBankClient> vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open()) 
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient client = _ConvertLineToClientObject(Line);
				vClient.push_back(client);
			}
			MyFile.close();
		}
		return vClient;
	}

	string _ConvertClientObjectToLine(clsBankClient client,string Seperator = "#//#") {
		string s1 = "";
		s1 += client.FirstName + Seperator;
		s1 += client.LastName + Seperator;
		s1 += client.Email + Seperator;
		s1 += client.Phone + Seperator;
		s1 += client.AccountNumber() + Seperator;
		s1 += client.PinCode + Seperator;
		s1 += to_string(client.AccountBalance);
		return s1;
	}

	void _SaveClientDataObject(vector<clsBankClient> vClient) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient& c : vClient) 
			{
				if(c._MatchCase == false){
					Line = _ConvertClientObjectToLine(c);
					MyFile << Line << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector<clsBankClient> vClient = _LoadingClientDataToFile();
		for (clsBankClient &c : vClient) {
			if (c.AccountNumber() == AccountNumber()) {
				c = *this;
				break;
			}
		}

		_SaveClientDataObject(vClient);
	}

	void _AddNew()
	{

		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out|ios::app);
		
		if (MyFile.is_open())
		{
			 
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	string _PrepareTransferLogRecord(double Amount, clsBankClient ClienTo, string UserName,string Seperator = "#//#") {
		string dataLine;
		dataLine += clsDate::GetSystemDateTimeString() + Seperator;
		dataLine += AccountNumber() + Seperator;
		dataLine += ClienTo.AccountNumber() + Seperator;
		dataLine += to_string(Amount) + Seperator;
		dataLine += to_string(AccountBalance) + Seperator;
		dataLine += to_string(ClienTo.AccountBalance) + Seperator;
		dataLine += UserName ;
		return dataLine;
	}

	void _RegisterTransferLog(double Amount, clsBankClient ClientTo,string UserName) {
		fstream MyFile;
		string Line = _PrepareTransferLogRecord(Amount, ClientTo, UserName);
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open()) {

			MyFile << Line << endl;

			MyFile.close();
		}
	}

	static stTransferLog _ConvertLineToDataTransferLog(string Line,string Seperator = "#//#") {

		vector<string> vTransfer = clsString::Split(Line,Seperator);
		stTransferLog stTrans;
		stTrans.DateTime = vTransfer[0];
		stTrans.sAcct = vTransfer[1];
		stTrans.dAcct = vTransfer[2];
		stTrans.Amount = stod(vTransfer[3]);
		stTrans.sBalance = stod(vTransfer[4]);
		stTrans.dBalance = stod(vTransfer[5]);
		stTrans.User = vTransfer[6];
		return stTrans;
	}

	/*static vector<stTransferLog> _LoadingTransferLogObject() {
		vector<stTransferLog> vTransfer;
		fstream MyFile;
		MyFile.open("TransferLog.txt",ios::in);
		if (MyFile.is_open()) {
			string Line;
			stTransferLog dataLine;
			while (getline(MyFile,Line))
			{
				dataLine = _ConvertLineToDataTransferLog(Line);
				vTransfer.push_back(dataLine);
			}
			MyFile.close();
		}
		return vTransfer;
	}*/
public:

	struct stTransferLog {
		string DateTime;
		string sAcct;
		string dAcct;
		double Amount;
		double sBalance;
		double dBalance;
		string User;
	};

	clsBankClient(enMode Mode, string FirstName,string LastName,string Email,string Phone,string AccountNumber,string PinCode,float Balance) 
		:clsPerson(FirstName,LastName,Email,Phone) 
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = Balance;
	}

	

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMod);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(put = SetPinCode, get = GetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(put = SetAccountBalance, get = GetAccountBalance)) float AccountBalance;

	/*void Print() {
		cout << "\nClient Card:";
		cout << "\n________________________________\n";
		cout << "First Name	: " << FirstName<<endl;
		cout << "Last Name	: " << LastName << endl;
		cout << "Full Name	: " << FullName() << endl;
		cout << "Email		: " <<	Email << endl;
		cout << "Phone		: " << Phone << endl;
		cout << "Account Number  : " << AccountNumber() << endl;
		cout << "Pin Code	: " << PinCode << endl;
		cout << "Account Balance : " << AccountBalance << endl;
		cout << "\n________________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			
			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				
				if (Client.AccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if ((Client.AccountNumber() == AccountNumber) && (Client.PinCode == PinCode)) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}


	enum enSaveResult {svFailedEmptyObject = 0, svSuccessed = 1 , svFaildAccountNumberExist};

	enSaveResult Save() {
		
		switch (_Mode)
		{
		case enMode::EmptyMod:
		{
			if(IsEmpty())
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
			if (clsBankClient::IsClientExist(_AccountNumber)) {
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

	static clsBankClient GetAddNewClientObject(string AccountNumber) 
	{		
		return clsBankClient(enMode::AddNewMode,"","","","", AccountNumber, "", 0);
	}

	bool Deleted() {
		vector<clsBankClient> vClient = _LoadingClientDataToFile();
		for (clsBankClient &c : vClient) {
			if (c.AccountNumber() == AccountNumber()) 
			{
				c._MatchCase = true;
				break;
			}
		}
		_SaveClientDataObject(vClient);
		
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientList() {
		return _LoadingClientDataToFile();
	}

	static double GetTotalBlances() {
		vector<clsBankClient> vClient = GetClientList();
		double TotalBalances = 0;
		for (clsBankClient &c : vClient) {
			TotalBalances += c.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}

	bool Withraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else{
		_AccountBalance -= Amount;
		Save();
		return true;
		}
	}

	bool Transfer(double Amount, clsBankClient &AccountTo,string UserName)
	{
		if (AccountBalance < Amount) {
			return false;
		}
		Withraw(Amount) ;
		AccountTo.Deposit(Amount);
		_RegisterTransferLog(Amount,AccountTo,UserName);
		return true;
	}

	static vector<stTransferLog> GetTransferLog() {
		vector<stTransferLog> vTransfer;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			stTransferLog dataLine;
			while (getline(MyFile, Line))
			{
				dataLine = _ConvertLineToDataTransferLog(Line);
				vTransfer.push_back(dataLine);
			}
			MyFile.close();
		}
		return vTransfer;
	}
};

