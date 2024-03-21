#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

#define FILE_NAME "time.dat"

void writeTime(int h, int m, int s)
{
    char str[9];
    fstream file;
    file.open(FILE_NAME, ios::out | ios::binary);
    if (!file)
    {
        cout << "Error in Creating File!!!" << endl;
        return;
    }
    snprintf(str, sizeof(str), "%02d:%02d:%02d", h, m, s);
    file.write(str, sizeof(str) - 1);
    cout << "Time " << str << " has been written into the file" << endl;
    file.close();
}

void readTime(int *h, int *m, int *s)
{
    char str[9];
    int inH, inM, inS;
    fstream finC;
    finC.open(FILE_NAME, ios::in | ios::binary);
    if (!finC)
    {
        cout << "Error in file opening..." << endl;
        return;
    }
    if (finC.read(str, sizeof(str) - 1))
    {
        sscanf(str, "%d:%d:%d", &inH, &inM, &inS);
        *h = inH;
        *m = inM;
        *s = inS;
    }
    finC.close();
}

int main()
{
    int m, h, s;

    cout << "Enter Time: \n";
    cout << "Enter Hour: \n";
    cin >> h;
    cout << "Enter Minute: \n";
    cin >> m;
    cout << "Enter Second: \n";
    cin >> s;

    writeTime(h, m, s);

    h = m = s = 0;

    readTime(&h, &m, &s);

    cout << "The Time is " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s << endl;

    return 0;
}
