#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class bankAccount
{
    protected:
        int account_number;
        double balance;
    public:
        bankAccount(){}
        bankAccount(int account_number, double balance);

        int get_account_number();
        int get_balance();

        void set_account_number(int);
        void set_balance(double);

        void withdraw(double);

        void deposit(double);

        void print();
};

#endif