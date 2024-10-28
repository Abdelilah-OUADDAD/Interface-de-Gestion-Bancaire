#pragma once

#include <iostream>

using namespace std;
class clsPerson
{
private:

    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;


public:


    clsPerson(string FirstName, string LastName, string Email, string Phone) {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }


    // set FirstName
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    // Get FirstName
    string GetFirstName() {
        return _FirstName;
    }
    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    // set LastName
    void SetLastName(string LastName) {
        _LastName = LastName;
    }
    // Get FirstName
    string GetLastName() {
        return _LastName;
    }
    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;


    // Get FullName
    string FullName() {
        return _FirstName + " " + _LastName;
    }

    // set Email
    void SetEmail(string Email) {
        _Email = Email;
    }
    // Get Email
    string GetEmail() {
        return _Email;
    }
    __declspec(property(get = GetEmail, put = SetEmail)) string Email;


    // set Phone
    void SetPhone(string Phone) {
        _Phone = Phone;
    }
    // Get Phone
    string GetPhone() {
        return _Phone;
    }
    __declspec(property(get = GetPhone, put = SetPhone)) string Phone;


};

