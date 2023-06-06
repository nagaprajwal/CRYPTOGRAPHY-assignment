#include <iostream>

using namespace std;

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    int x, y;

    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;

    int gcd = extendedEuclidean(a, b, x, y);

    cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
   

    return 0;
}
