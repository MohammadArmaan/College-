#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("Sample.txt", ios::out);

    if(!file)
    {
        cout<<"Error in Creating File!"<<endl;
        return 0;
    }
    cout<<"File Created Successfully"<<endl;
    file<<"ABCD";
    file.close();

    file.open("Sample.txt", ios::in);
    
    if(!file)
    {
        cout<<"Error in Opening File"<<endl;
        return 0;
    }

    char ch;
    cout<<"File Content";

    while(!file.eof())
    {
        file>>ch;
        cout<<ch;
    }

    file.close();


    return 0;
}