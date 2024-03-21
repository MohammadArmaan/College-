#include<iostream>
using namespace std;

int main()
{
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    cout<<"Enter the Array Index: ";
    cin>>index;

    try
    {
        if(index > 4)
        {
            throw "Array out of Bound!!!";
        }

        cout<<"Enter Numerator: ";
        cin>>numerator;

        cout<<"Enter Denominator: ";
        cin>>denominator;

        if(denominator == 0)
        {
            throw 0;
        }

        arr[index] = numerator/ denominator;

        cout<<"Result: "<<arr[index]<<endl;

    }
    catch(const char *message)
    {
        cout<<message<<endl;
    }

    catch(int n)
    {
        cout<<"Cannot Divide by Zero! Try Oher Number than "<<n<<endl;
    }

    catch(...)
    {
        cout<<"Unexpected Error!!!"<<endl;
    }
    
}