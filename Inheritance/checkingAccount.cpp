#include "checkingAccount.h"

#include <iostream>

using namespace std;

checkingAccount::checkingAccount(int number, double depo, double rate, double charge, double min)
{
    this->account_number = number;
    this->balance = depo;
    this->interest_rate = rate;
    this->service_charges = charge;
    this->minimum_balance = min;
}

double checkingAccount::get_interest_rate(){return this->interest_rate;}

double checkingAccount::get_minimum_balance(){return this->minimum_balance;}

double checkingAccount::get_service_charges(){return this->service_charges;}

void checkingAccount::set_interest_rate(double interest_rate) {this->interest_rate = interest_rate;}

void checkingAccount::set_minimum_balance(double minimum_balance){this->minimum_balance = minimum_balance;}

void checkingAccount::set_service_charges(double service_charges){this->service_charges = service_charges;}

double checkingAccount::interest() {return (this->interest_rate)*(this->balance);}

void checkingAccount::write(){}

bool checkingAccount::verify()
{
    if((this->balance) < (this->minimum_balance))
    {
        return false;
    }

    return true;
}

void checkingAccount::withdraw(double value) {this->balance -= value;}

void checkingAccount::print()
{
    cout << "Account Number: " << this->account_number << "\n";
    cout << "Balance: " << this->balance << "\n";
    cout << "Interest Rate: " << this->interest_rate << "\n";
    cout << "Minimum Balance: " << this->minimum_balance << "\n";
    cout << "Service Charge: " << (checkingAccount::verify() ? 0:this->service_charges) << "\n";
    cout << "Interest: " << checkingAccount::interest() << endl;
}