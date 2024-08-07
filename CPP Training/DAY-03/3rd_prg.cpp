#include<iostream>
#include<cmath>
using namespace std;

int main(){
    double value = 0.707; // Value of sin, cos or tan
    cout << "asin(" << value << ") = " << asin(value) * (180 / M_PI) << " degrees" << endl;
    cout << "acos(" << value << ") = " << acos(value) * (180 / M_PI) << " degrees" << endl;
    cout << "atan(" << value << ") = " << atan(value) * (180 / M_PI) << " degrees" << endl;
    return 0;
}