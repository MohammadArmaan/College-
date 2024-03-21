#include<iostream>
using namespace std;

class Number
{
    int val;
    public:
        Number(int n): val(n) {}
        void display()
        {
            cout<<"The Number is: "<<val<<endl;
        }

        Number operator - ()
        {
            val = -val;
            return Number(val);
        }

};

int main()
{
    Number n1(2), n2(-3);
    n1 =  -n1;
    n1.display();

    n2 =  -n2;
    n2.display();

    return 0;
}