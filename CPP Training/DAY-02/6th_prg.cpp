#include<iostream>
#include<string>
using namespace std;

string decimalToBinary(int n){
    string binaryNumber = "";
    if(n == 0){
        return "0";
    }
    while(n > 0){
        char bit = (n % 2) + '0';
        binaryNumber = bit + binaryNumber;
        n /= 2;
    }
    return binaryNumber;

}

int main(){
    int decimal;
    cout<<"Enter Decimal Number: ";
    cin>>decimal;
    cout<<"Binary: "<<decimalToBinary(decimal)<<endl;
    return 0;
}
