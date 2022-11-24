#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include "bankAccount.h"

class savingAccount : public bankAccount
{
    private:
        double interest_rate;
    public:
        savingAccount(){}
        savingAccount(int number, double depo, double rate);

        void set_interest_rate(double);
        double interest();
        void withdraw(double);
        void print();
};

#endif