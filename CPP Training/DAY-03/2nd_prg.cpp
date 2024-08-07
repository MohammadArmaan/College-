#include <iostream>
#include <cmath>
 using namespace std;
int main() {
    double angle = 45; // Angle in degrees
    double radians = angle * (M_PI / 180); // Convert to radians
    cout << "sin(" << angle << ") = " << sin(radians) << endl;
    cout << "cos(" << angle << ") = " << cos(radians) << endl; cout << "tan(" << angle << ") = " << tan(radians) << endl;

return 0;
}