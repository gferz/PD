#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankAccount.h"

class checkingAccount : public bankAccount
{
    private:
        double interest_rate;
        double minimum_balance;
        double service_charges;
    public:
        checkingAccount(){}
        checkingAccount(int number, double depo, double rate, double charge, double min);

        double get_interest_rate();
        double get_minimum_balance();
        double get_service_charges();

        void set_interest_rate(double);
        void set_minimum_balance(double);
        void set_service_charges(double);

        double interest();

        void write();

        bool verify();

        void withdraw(double);

        void print();
};

#endif