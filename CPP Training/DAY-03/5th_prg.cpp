#include <iostream>
using namespace std;
int main() {
    cout << "ASCII Table (0 - 127):" << endl;
    cout << "=======================" << endl;
    for (int i = 0; i <= 127; ++i) {
    cout << "ASCII code " << i << ": " << char(i) << endl;
    }
    return 0;
}