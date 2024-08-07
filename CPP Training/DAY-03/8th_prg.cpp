#include <iostream> 
using namespace std;
int main() { 
    int a, b;
    cout << "Enter two numbers: "; cin>>a>>b;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    a=a^b; 
    b=a^b; 
    a=a^b;
    cout << "A􏰁er swapping: a = " << a << ", b = " << b << endl;
    return 0; 
}