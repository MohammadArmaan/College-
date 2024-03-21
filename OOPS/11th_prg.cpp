#include<iostream>
using namespace std;

int ZeroDivisionError(int x, int y)
{
    if(y == 0)
    {
        throw "Zero Division Error!";
    }
    return (x/y);
}

int main()
{
    int a = 10;
    int b = 0;
    int c;

    try
    {
        c = ZeroDivisionError(a, b);
        cout<<"Result: "<<c<<endl;
    }

    catch(const char *message)
    {
        cout<<message<<endl;
    }

    return 0;
}