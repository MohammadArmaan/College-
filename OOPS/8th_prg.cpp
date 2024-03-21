#include<iostream>
using namespace std;

class N1
{
    int val1;
    public: 
        N1(int n): val1(n)
        {
            cout<<"***N1 Constructor Called"<<endl;
        }

        int get_n1()
        {
            return val1;
        }

};

class N2
{
    int val2;
    public:
        N2(int n): val2(n)
        {
            cout<<"***N2 Constructor Called"<<endl;
        }

        int get_n2()
        {
            return val2;
        }
};


class Add: public N1, public N2
{
    int res;
    public:
        Add(int a, int b): N1(a), N2(b), res(0) {}

        void add_dis()
        {
            res = get_n1() + get_n2();
            cout<<"Result is: "<<res<<endl;
        }

};

int main()
{
    int a, b;
    cout<<"Enter two numbers for Addition: ";
    cin>>a>>b;

    Add a1(a, b);
    a1.add_dis();

    return 0;
}