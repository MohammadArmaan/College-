#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout<<"Enter 3 numbers to check the largest of two numbers: ";
    cin>>a>>b>>c;

    if(a > b && a > c)
    {
        cout<<a<<" is greater than "<<b<<" & "<<c;
    }

    if(a > b && a > c)
    {
        cout<<b<<" is greater than "<<a<<" & "<<c;
    }

    else
    {
        cout<<c<<" is greater than "<<a<<" & "<<b;
    }

    return 0;
}