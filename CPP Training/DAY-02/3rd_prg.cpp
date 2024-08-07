#include<iostream>
#include<string>
using namespace std;

int hexadecimal(string hexVal){
    int len = hexVal.size();
    int base = 1;
    int decVal = 0;
    for(int i = len - 1; i >= 0; i--){
        if(hexVal[i] >= '0' && hexVal[i] <= '9'){
            decVal += (int(hexVal[i]) - 48) * base;
            base *= 16;
        }
        if(hexVal[i] >= 'A' && hexVal[i] <= 'F'){
            decVal += (int(hexVal[i]) - 55) * base;
            base *= 16;
        }
    }
    return decVal;
}

int main(){
    string hexVal;
    cout<<"Enter a Hexadecimal Number: ";
    cin>>hexVal;
    cout<<"Hexadecimal to Decimal Value: "<<hexadecimal(hexVal)<<endl;
    return 0;
}