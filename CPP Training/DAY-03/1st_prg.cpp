#include <iostream>
#include <cmath>
using namespace std;
double geometricSum(double a, double r, int n) { 
    if(r==1)
        return a * n; else
    return a*(1-pow(r,n))/(1-r); 
}
int main() { 
    double a, r; int n;
    cout << "Enter the first term (a): ";
    cin >> a;
    cout << "Enter the common ratio (r): "; cin >> r;
    cout << "Enter the number of terms (n): "; cin >> n;
    cout << "Sum of the geometric progression series: " << geometricSum(a, r, n) << endl;
    return 0; 
}
