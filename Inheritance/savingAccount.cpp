#include "savingAccount.h"

#include <iostream>

using namespace std;

savingAccount::savingAccount(int number, double depo, double rate)
{
    this->account_number = number;
    this->balance = depo;
    this->interest_rate = rate;
}

void savingAccount::set_interest_rate(double interest_rate) 
{
    this->interest_rate = interest_rate;
    this->account_number = account_number;
    this->balance = balance;
}

double savingAccount::interest() {return (this->interest_rate)*(this->balance);}

void savingAccount::withdraw(double value) {this->balance -= value;}

void savingAccount::print()
{
    cout << "Account number: " << this->account_number << "\n";
    cout << "Balance: " << this->balance << "\n";
    cout << "Interest Rate: " << this->interest_rate << "\n";
    cout << "Interest: " << savingAccount::interest() << endl;
}