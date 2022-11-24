#include "bankAccount.h"
#include "savingAccount.h"
#include "checkingAccount.h"

#include <iostream>

using namespace std;

//#define EMPLOYEE //uncomment untuk merubah nilai minimum balance, service charge, dan interest rate secara bebas
#define CHECKING //comment untuk merubah ke saving

void menu1();
void menu2();

int main()
{
    double min = 50;
    double charge = 10;
    double rate = 0.1;

    #ifdef EMPLOYEE
    cout << "Minimum balance : "; cin >> min;
    cout << "Service charge: "; cin >> charge;
    cout << "Interest rate: "; cin >> rate;
    #endif

    #ifdef CHECKING
    int number;
    int depo;

    cout << "Buat akun bank!" << "\n";
    cout << "Buat nomor rekeningmu: "; cin >> number;
    cout << "Setor: "; cin >> depo;
    checkingAccount cek(number,depo,rate,charge,min);

    int pilih,ganti;
    double tarik,setor,ck;
    while(true)
    {
        menu1(); cin >> pilih;
        if(pilih==1)
        {
            cout << "Inging menarik sebanyak: "; cin >> tarik;
            if(cek.get_balance()>tarik)
            {
                cek.withdraw(tarik);
                cout << "Anda telah menarik sebanyak" <<tarik<< ", saldo anda = " << cek.get_balance() << endl;
            }
            else
            {
                cout << "Tidak valid" << endl;
            }
        }
        else if(pilih==2)
        {
            cout << "Setor sebanyak: "; cin >> setor;
            cek.deposit(setor);
            cout << "Anda berhasil menyetor sebanyak " << setor << ", saldo anda: " << cek.get_balance() << endl;
        }
        else if(pilih==3)
        {
            cek.print();
        }
        else if(pilih==4)
        {
            cout << "Buat nomor rekening baru: "; cin >> ganti;
            cek.set_account_number(ganti);
            cout << "Anda telah memiliki nomor rekeing baru: " << cek.get_account_number() << endl;
        }
        else if(pilih==5)
        {
            cout << "Membuat cek senilai: "; cin >> ck;
            if(cek.get_balance()>ck)
            {
                cek.withdraw(ck);
                cout << "Berhasil membuat cek, saldo anda : " << cek.get_balance();
            }
            else
            {
                cout << "Tidak valid" << endl;
            }
        }
        else if(pilih==6)
        {
            return 0;
        }
        else
        {
            cout << "Tidak valid" << endl;
        }
    }

    #else
    int number;
    int depo;

    cout << "Buat akun bank!" << "\n";
    cout << "Buat nomor rekeningmu: "; cin >> number;
    cout << "Setor: "; cin >> depo;
    savingAccount sv(number,depo,rate);
    while(true)
    {
        int pilih,ganti;
        double tarik,setor;
        
        menu2(); cin >> pilih;
        if(pilih==1)
        {
            cout << "Inging menarik sebanyak: "; cin >> tarik;
            if(sv.get_balance()>tarik)
            {
                sv.withdraw(tarik);
                cout << "Anda telah menarik sebanyak" <<tarik<< ", saldo anda = " << sv.get_balance() << endl;
            }
            else
            {
                cout << "Tidak valid" << endl;
            }
        }
        else if(pilih==2)
        {
            cout << "Setor sebanyak: "; cin >> setor;
            sv.deposit(setor);
            cout << "Anda berhasil menyetor sebanyak " << setor << ", saldo anda: " << sv.get_balance() << endl;
        }
        else if(pilih==3)
        {
            sv.print();
        }
        else if(pilih==4)
        {
            cout << "Buat nomor rekening baru: "; cin >> ganti;
            sv.set_account_number(ganti);
            cout << "Anda telah memiliki nomor rekeing baru: " << sv.get_account_number() << endl;
        }
        else if(pilih==5)
        {
            return 0;
        }
        else
        {
            cout << "Tidak valid" << endl;
        }
    }
    #endif

    return 0;
}

void menu1()
{
    cout << "Tentukan pilhan di bawah!" << "\n";
    cout << "1. Tarik" << "\n";
    cout << "2. Setor" << "\n";
    cout << "3. Informasi" << "\n";
    cout << "4. Ganti nomor rekening" << "\n";
    cout << "5. Membuat cek" << "\n";
    cout << "6. Exit" << "\n";
    cout << "Pilih: ";
}

void menu2()
{
    cout << "Tentukan pilhan di bawah!" << "\n";
    cout << "1. Tarik" << "\n";
    cout << "2. Setor" << "\n";
    cout << "3. Informasi" << "\n";
    cout << "4. Ganti nomor rekening" << "\n";
    cout << "5. Exit" << "\n";
    cout << "Pilih: ";
}
