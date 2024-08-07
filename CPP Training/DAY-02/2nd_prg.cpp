#include<iostream>
#include<cmath>
using namespace std;

int octalToDecimal(int octalNumber){
    int decimalNumber = 0, i =0;
    while(octalNumber != 0){
        decimalNumber += (octalNumber % 10) * pow(8, i);
        ++i;
        octalNumber /= 10;

    }
    return decimalNumber;
}

int main(){
    int octalNumber;
    cout<<"Enter an Octal Number: ";
    cin>>octalNumber;
    cout<<"Decimal: "<<octalToDecimal(octalNumber)<<endl;
    return 0;
}