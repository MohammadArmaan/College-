#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b)) 
using namespace std;
int main() {
    int x=10,y=20;
    cout << "Maximum value is: " << MAX(x, y) << endl;
    return 0; 
}