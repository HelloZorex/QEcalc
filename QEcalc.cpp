#include <iostream>
#include <cmath>
#include <complex>
using namespace std;

int *getinput() {
    static int varLst[3];
    string abc[3] = {"a", "b", "c"};
    for(int i = 0; i <= 2; i++) {
        cout << abc[i] << ": ";
        cin >> varLst[i];
    } 
    return varLst;
}

double qe(int a1, int b1, int c1) {
    double xCoord, yCoord, zero1, zero2;
    double a = double(a1), b = double(b1), c = double(c1);
    xCoord = ceil(((-b)/(2*a))*100)/100;
    yCoord = ceil(((a*pow(xCoord, 2))+(b*xCoord)+c)*100)/100;
    complex<double> disc = sqrt(complex<double>(pow(b, 2)-(4*a*c)));
    cout << "x: " << xCoord << " y: " << yCoord << endl;
    if(disc.imag() == 0) {
        zero1 = ceil(((-b-real(disc))/(2*a))*100)/100;
        zero2 = ceil(((-b+real(disc))/(2*a))*100)/100;
        cout << zero1 << ", " << zero2 << endl;
    } else {
        zero1 = ceil(((-b-imag(disc))/(2*a))*100)/100;
        zero2 = ceil(((-b+imag(disc))/(2*a))*100)/100;
        cout << zero1 << "i, " << zero2 << "i" << endl;
    }
    return 0;
}

int main() {
    cout << "Enter a, b, c for ax^2+bx+c" << endl;
    int *arrin;
    arrin = getinput();
    qe(arrin[0], arrin[1], arrin[2]);
    return 0;
}
