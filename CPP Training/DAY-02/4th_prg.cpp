#include<iostream>
#include<string>
using namespace std;

string decimalToBase(int n, int base){
    string digits = "0123456789ABCDEF";
    string result = "";
    while(n > 0){
        result = digits[n % base] + result;
        n /= base;

    }
    return result;

}

int main(){
    int n, base;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"Enter the Base: ";
    cin>>base;
    cout<<"Deciaml to Any Conversion: "<<decimalToBase(n, base)<<endl;
}