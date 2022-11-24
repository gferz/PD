#include "bankAccount.h"
#include <iostream>

using namespace std;

bankAccount::bankAccount(int account_number, double balance)
{
    this->account_number = account_number;
    this->balance = balance;
}

int bankAccount::get_account_number() {return this->account_number;}

int bankAccount::get_balance() {return this->balance;}

void bankAccount::set_account_number(int account_number) {this->account_number = account_number;}

void bankAccount::set_balance(double balance) {this->balance = balance;}

void bankAccount::withdraw(double value) {this->balance -= value;}

void bankAccount::deposit(double value) {this->balance += value;}

void bankAccount::print()
{
    cout << "Account Number: " << this->account_number << "\n";
    cout << "Balance: " << this->balance << endl;
}