#include<iostream>
using namespace std;

double celsiusToFarenheit(int celsius){
    return celsius * (9 / 5) + 32;
}

double farenheitToCelsius(int farenheit){
    return (farenheit - 32) * (5 / 9);
}

int main(){
    int celsius, farenheit;
    cout<<"Enter Celsius value to find out Farenheit: ";
    cin>>celsius;
    cout<<"Enter Farenheit value to find out Celsius: ";
    cin>>farenheit;
    cout<<"Celsius to Farenheit: "<<celsiusToFarenheit(celsius)<<endl;
    cout<<"Farenheit to Celsius: "<<farenheitToCelsius(farenheit)<<endl;
    return 0;
}