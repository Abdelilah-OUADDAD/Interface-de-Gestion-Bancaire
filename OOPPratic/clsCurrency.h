#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "Global.h"
#include "clsUtil.h"

using namespace std;
class clsCurrency 
{

private:
	enum enMode { EmptyMod = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencieObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencie = clsString::Split(Line, Seperator);
		return clsCurrency(enMode::UpdateMode, vCurrencie[0], vCurrencie[1], vCurrencie[2],stof( vCurrencie[3]));
	}

	static clsCurrency _GetEmptyCurrenciesObject() {
		return clsCurrency(enMode::EmptyMod, "", "", "", 0);
	}

	static vector<clsCurrency> _LoadingCurrenciesDataToFile() {
		vector<clsCurrency> vCurrencie;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currencie = _ConvertLineToCurrencieObject(Line);
				vCurrencie.push_back(Currencie);
			}
			MyFile.close();
		}
		return vCurrencie;
	}

	string _ConvertCurrenciesObjectToLine(clsCurrency Currencie, string Seperator = "#//#") {
		string s1 = "";
		s1 += Currencie.Country() + Seperator;
		s1 += Currencie.CurrencyCode() + Seperator;
		s1 += Currencie.CurrencyName() + Seperator;
		s1 += to_string( Currencie.Rate());
		
		return s1;
	}

	void _SaveCurrenciesDataObject(vector<clsCurrency> vCurrencie) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsCurrency& c : vCurrencie)
			{
				Line = _ConvertCurrenciesObjectToLine(c);
				MyFile << Line << endl;
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector<clsCurrency> vCurrencie = _LoadingCurrenciesDataToFile();
		for (clsCurrency& c : vCurrencie) {
			if (c.CurrencyCode() == CurrencyCode()) {
				c = *this;
				break;
			}
		}

		_SaveCurrenciesDataObject(vCurrencie);
	}

public:

	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName,float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMod);
	}

	string Country() {
		return _Country;
	}

	string CurrencyCode() {
		return _CurrencyCode;
	}

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(float Rate) {
		_Rate = Rate;
		_Update();
	}

	float Rate() {

		return _Rate;
	}


	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperCaseAllLetterOfString(Country);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currencie = _ConvertLineToCurrencieObject(Line);

				if ((clsString::UpperCaseAllLetterOfString(Currencie.Country()) == Country))
				{
					MyFile.close();
					return Currencie;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrenciesObject();
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperCaseAllLetterOfString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currencie = _ConvertLineToCurrencieObject(Line);

				if (Currencie.CurrencyCode() == CurrencyCode) {
					MyFile.close();
					return Currencie;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrenciesObject();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency currencie = FindByCode(CurrencyCode);
		return (!currencie.IsEmpty());
	}

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadingCurrenciesDataToFile();
	}

	float ConvertToUSD(float Amount) {
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount,clsCurrency Currency2) {
		float AmountInUsd = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD"){
			return AmountInUsd;
		}
		return (float)(AmountInUsd * Currency2.Rate());

	}
};

