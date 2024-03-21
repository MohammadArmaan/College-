#include<iostream>
using namespace std;

void add(int, int);
void add(double, double);

void accept(int &, int &);
void accept(double &, double &);

int main()
{
    int a, b;
    double c, d;

    accept(a,b);
    accept(c, d);

    add(a, b);
    add(c, d);

    return 0;

}

void accept(int &a, int &b)
{
    cout<<"Enter 2 Integer Numbers: ";
    cin>>a>>b;
}

void accept(double &c, double &d)
{
    cout<<"Enter 2 Double Numbers: ";
    cin>>c>>d;
}

void add(int a, int b)
{
    cout<<"Additon the 2 Integers: "<<(a+b)<<endl;
}

void add(double c, double d)
{
    cout<<"Additon the 2 Floating Numbers: "<<(c+d)<<endl;
}


