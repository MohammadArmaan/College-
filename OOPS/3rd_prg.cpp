#include<iostream>
using namespace std;

class Student
{
    char name[30], rno[20];
    int m[2], total;

    public:
        void accept();
        void display();

};

void Student::accept()
{
    cout<<"Enter the name of Student: ";
    cin>>this->name;

    cout<<"Enter the USN of the Student: ";
    cin>>this->rno;

    cout<<"Enter the marks of Subjects: ";
    cin>>m[0]>>m[1];

    total = this->m[0] + this->m[1];
}

void Student::display()
{
    cout<<"Name: "<<name<<endl;
    cout<<"USN: "<<rno<<endl;
    cout<<"Marks of the Subjects: "<<m[0]<<" "<<m[1]<<endl;
    cout<<"Total: "<<total<<endl;

}

int main()
{
    Student s1;
    s1.accept();
    s1.display();
}