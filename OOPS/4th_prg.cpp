#include<iostream>
using namespace std;

class Bank
{
    char name[30];
    unsigned int acc_no;
    int bal;
    public:
        void accept();
        void display();
        void transaction();
};

void Bank::accept()
{
    cout<<"Enter the Name: ";
    cin>>name;

    cout<<"Enter Account Number: ";
    cin>>acc_no;

    cout<<"Enter the Balance Ammount: ";
    cin>>bal;
}

void Bank::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Account Number: "<<acc_no<<endl;
    if(bal<500)
    {
        cout<<"Invalid Bank Balance!"<<endl;
    }
    else
    {
        cout<<"Balnce Ammount:  "<<bal<<endl;
    }
}

void Bank::transaction()
{
    int ch, amt;
    cout<<"Bank Operations\n1. Deposit\n2.Withdraw\nEnter your choice: \n";
    cin>>ch;
    cout<<"Enter the Ammount: ";
    cin>>amt;
    if(bal < amt)
    {
        cout<<"Invalid Transaction";
        return; 
    }

    if(ch == 1)
    {
        bal = bal + amt;
        cout<<"Balnce Ammount: "<<bal<<endl;
    }
    else if(ch == 2)
    {
        bal = bal - amt;
        cout<<"Balance Ammount"<<bal<<endl;
    }
}

int main()
{
    Bank b1;
    b1.accept();
    b1.transaction();
    b1.display();
}
