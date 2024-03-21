#include<iostream>
using namespace std;

class Base
{
    int alpha;
    char beta;
    float gamma;

    public: 
        Base(int a, char b, float g): alpha(a), beta(b), gamma(g)
        {
            cout<<"Base Class Constructor Called"<<endl;
        }

        void display()
        {
            cout<<"Alpha: "<<alpha<<endl;
            cout<<"Beta: "<<beta<<endl;
            cout<<"Gamma: "<<gamma<<endl;
        }
};

class Derived: public Base
{
    public: 
        Derived(int a, char b, float g): Base(a, b, g)
        {
            cout<<"Derived Class Constructor Called"<<endl;
        }

};

int main()
{
    Derived d1(1, 'A', 1.1);
    d1.display();
}
