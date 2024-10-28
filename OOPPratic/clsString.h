#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;
class clsString
{
private:
    string _Value;

public:

    clsString() {
        _Value = "";
    }

    clsString(string Value) {
        _Value = Value;
    }

    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue))	string Value;

    static short Length(string s1) {
        return s1.length();
    }
    short Length() {
        return _Value.length();
    }

    static string UpperCaseFirstLetterOfString(string Text) {
        bool isFirstLetter = true;

        cout << "\nString After Conversion\n";
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ' && isFirstLetter) {
                Text[i] = toupper(Text[i]);
            }
            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }

    void UpperCaseFirstLetterOfString() {
        _Value = UpperCaseFirstLetterOfString(_Value);
    }

    static string LowerCaseFirstLetterOfString(string Text) {
        bool isFirstLetter = true;
        cout << "\nString After Convert\n";
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ' && isFirstLetter) {
                Text[i] = tolower(Text[i]);
            }
            isFirstLetter = (Text[i] == ' ' ? true : false);
        }
        return Text;
    }
    void LowerCaseFirstLetterOfString() {
        _Value = LowerCaseFirstLetterOfString(_Value);
    }

    static string LowerCaseAllLetterOfString(string Text) {

        // cout << "\nString After Lower\n";
        for (int i = 0; i < Text.length(); i++) {
            Text[i] = tolower(Text[i]);
        }

        return Text;

    }
    void LowerCaseAllLetterOfString() {
        _Value = LowerCaseAllLetterOfString(_Value);
    }

    static string UpperCaseAllLetterOfString(string Text) {

        //cout << "\nString After Upper\n";
        for (int i = 0; i < Text.length(); i++) {
            Text[i] = toupper(Text[i]);
        }

        return Text;

    }
    void UpperCaseAllLetterOfString() {
        _Value = UpperCaseAllLetterOfString(_Value);
    }

    static void PrintFirstLetterOfString(string Text) {

        bool isFirstLetter = true;

        cout << "\First Letter of this String\n";
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != ' ' && isFirstLetter) {
                cout << Text[i] << endl;
            }
            isFirstLetter = (Text[i] == ' ' ? true : false);
        }

    }
    void PrintFirstLetterOfString() {
        PrintFirstLetterOfString(_Value);
    }

    static char InvertCase(char Letter) {

        return isupper(Letter) ? tolower(Letter) : toupper(Letter);

    }

    enum enWhatToCount { Small = 0, Capital = 1, All = 3 };

    static short CountLetter(string Text, enWhatToCount WhatToCount = enWhatToCount::All) {
        short CountLet = 0;

        if (WhatToCount == 3) {
            return Text.length();
        }
        for (int i = 0; i < Text.length(); i++) {

            if (WhatToCount == 0 && islower(Text[i])) {
                CountLet++;

            }
            if (WhatToCount == 1 && isupper(Text[i])) {
                CountLet++;

            }

        }
        return CountLet;

    }

    static short CountCapitalLettersCase(string Text) {
        short countCapital = 0;
        for (int i = 0; i < Text.length(); i++) {
            if (isupper(Text[i])) {
                countCapital++;
            }
        }
        return countCapital;
    }
    short CountCapitalLettersCase() {
        return CountCapitalLettersCase(_Value);
    }


    static short CountSmallLettersCase(string Text) {
        short countSmall = 0;
        for (int i = 0; i < Text.length(); i++) {
            if (islower(Text[i])) {
                countSmall++;
            }
        }
        return countSmall;
    }
    short CountSmallLettersCase() {
        return  CountSmallLettersCase(_Value);
    }


    static string InvertCaseString(string Text) {

        for (int i = 0; i < Text.length(); i++) {

            Text[i] = InvertCase(Text[i]);

        }
        return Text;
    }
    void InvertCaseString() {
        _Value = InvertCaseString(_Value);
    }


    static short CountCharacter(string Text, char Letter, bool MatchCase = true) {
        short Counter = 0;
        for (int i = 0; i < Text.length(); i++) {
            if (MatchCase) {
                if (Text[i] == Letter) {
                    Counter++;
                }
            }
            else {
                if (toupper(Text[i]) == toupper(Letter)) {
                    Counter++;
                }
            }

        }
        return Counter;
    }
    short CountCharacter(char Letter, bool MatchCase = true) {
        return CountCharacter(_Value, Letter, MatchCase);
    }

    static bool CheckVowel(char Letter) {
        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'o' || Letter == 'i' || Letter == 'e' || Letter == 'u');

    }

    static short CountVowel(string Text) {
        short Counter = 0;
        for (int i = 0; i < Text.length(); i++) {
            if (CheckVowel(Text[i])) {
                Counter++;
            }
        }
        return Counter;
    }
    short CountVowel() {
        return CountVowel(_Value);
    }


    static void PrintVowel(string Text) {
        short Counter = 0;
        for (int i = 0; i < Text.length(); i++) {
            if (CheckVowel(Text[i])) {
                cout << setw(3) << Text[i] << "  ";
            }
        }
    }
    void PrintVowel() {
        PrintVowel(_Value);
    }

    static void PrintEachWordInString(string Text) {
        string delmi = " ";
        string word;
        short pos = 0;

        while ((pos = Text.find(delmi)) != string::npos) {
            word = Text.substr(0, pos);
            if (word != "") {
                cout << word << "\n";
            }
            Text.erase(0, pos + delmi.length());
        }

        if (Text != "") {
            cout << Text;
        }
    }
    void PrintEachWordInString() {
        PrintEachWordInString(_Value);
    }

    static short CountEachWordInString(string Text) {
        string delmi = " ";
        short pos = 0;
        string word;
        short counter = 0;
        while ((pos = Text.find(delmi)) != std::string::npos) {
            word = Text.substr(0, pos);
            if (word != "") {
                counter++;
            }
            Text.erase(0, pos + delmi.length());
        }
        if (Text != "") {
            counter++;
        }
        return counter;
    }
    short CountEachWordInString() {
        return CountEachWordInString(_Value);
    }



    static vector<string> Split(string Text, string delmi) {


        vector<string> vSplit;
        int pos = 0;
        string word = "";

        while ((pos = Text.find(delmi)) != string::npos) {
            word = Text.substr(0, pos);
            if (word != "") {
                vSplit.push_back(word);
            }
            Text.erase(0, pos + delmi.length());
        }
        if (Text != "") {
            vSplit.push_back(Text);
        }
        return vSplit;

    }
    vector<string> Split(string delmi) {
        return Split(_Value, delmi);
    }

    static string TrimLeft(string Text) {

        char delmi = ' ';
        for (int i = 0; i < Text.length(); i++) {
            if (Text[i] != delmi) {
                return Text.substr(i, Text.length() - i);
            }
        }
        return "";
    }
    void TrimLeft() {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string Text) {

        char delmi = ' ';
        for (int i = Text.length() - 1; i > 0; i--) {
            if (Text[i] != delmi) {

                return Text.substr(0, i + 1);
            }
        }
        return "";
    }
    void TrimRight() {
        _Value = TrimRight(_Value);
    }

    static string Trim(string Text) {

        return TrimRight(TrimLeft(Text));

    }
    void Trim() {
        _Value = Trim(_Value);
    }

    static string join(vector<string> vText, string delmi) {
        string word = "";
        short j = 0;

        for (string& i : vText) {
            j++;
            if (j != 3) {
                word += i + "   " + delmi;
            }
            else {
                word += i + "\t\t" + delmi;
            }
        }

        return word.substr(0, word.length() - delmi.length());
    }

    static string join(string arrText[], short Length, string delmi) {
        string word = "";
        for (int i = 0; i < Length; i++) {
            word += arrText[i] + delmi;
        }

        return word.substr(0, word.length() - delmi.length());
    }

    static string ReserveString(string Text, string delmi) {

        vector<string> vSplit = Split(Text, delmi);
        string word = "";
        vector<string>::iterator iter;
        iter = vSplit.end();
        while (iter != vSplit.begin()) {
            iter--;
            word += *iter + delmi;

        }
        return word.substr(0, word.length() - delmi.length());
    }
    void ReserveString(string delmi) {
        _Value = ReserveString(_Value, delmi);
    }

    static string ReplaceWordInString(string Text, string delmi, string Replace, string ReplaceTo) {

        short pos = Text.find(Replace);

        while (pos != string::npos) {

            Text = Text.replace(pos, Replace.length(), ReplaceTo);
            pos = Text.find(Replace);

        }
        return Text;
    }
    void ReplaceWordInString(string delmi, string Replace, string ReplaceTo) {
        _Value = ReplaceWordInString(_Value, delmi, Replace, ReplaceTo);
    }

    static string ReplaceWordInStringUsingSplit(string Text, string Replace, string ReplaceTo, bool MatchCase = true) {

        vector<string> vSplit = Split(Text, " ");

        for (string& s : vSplit) {
            if (MatchCase) {
                if (s == Replace) {
                    s = ReplaceTo;
                }
            }
            else {
                if (LowerCaseAllLetterOfString(s) == LowerCaseAllLetterOfString(Replace)) {
                    s = ReplaceTo;
                }
            }
        }

        return join(vSplit, " ");

    }
    void ReplaceWordInStringUsingSplit(string Replace, string ReplaceTo) {
        _Value = ReplaceWordInStringUsingSplit(_Value, Replace, ReplaceTo);
    }

    static string RemoveAllPunctuations(string Text) {
        string s = "";
        for (int i = 0; i < Text.length(); i++) {

            if (!ispunct(Text[i])) {
                s += Text[i];
            }
        }
        return s;
    }
    void RemoveAllPunctuations() {
        _Value = RemoveAllPunctuations(_Value);

    }

};



