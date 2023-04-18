#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float a, b, c, x1, x2, discriminant, real, imaginary;
    cout << "Enter the coefficients: ";
    cin >> a >> b >> c;
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "x1 = " << x1 << "\n";
        cout << "x2 = " << x2 << "\n";
    }
    
    else if (discriminant == 0) {
        x1 = -b/(2*a);
        cout << "x1 and x2 =" << x1 << "\n";
    }

    else {
        real = -b/(2*a);
        imaginary =sqrt(-discriminant)/(2*a);
        cout << "x1 = " << real << "+" << imaginary << "i" << "\n";
        cout << "x2 = " << real << "-" << imaginary<< "i" << "\n";
    }

    return 0;
}