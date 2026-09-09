#include <iostream>
#include <cmath>
using namespace std;

double calculateB(double x, double y, double z) {
    return ((y + atan(pow((fabs(pow(x, 2) + z)), 1/3))) / (2*z + x + pow(sin(pow(y, 3)), 2))) + exp(-((x + z)/(x + 1)));
}

double calculateA(double x, double y, double z, double b) {
    return (pow((1+y), 2)) * (((pow((fabs(x+y)), 0.3)) / pow(b, 2) + z) / (1 + exp(-(x-y)) + pow(fabs(y), 0.43)));
}

int main(){
    double x = 0.48, y = 0.47, z = 1.32;

    double b = calculateB(x, y, z);
    double a = calculateA(x, y, z, b);

    cout << "task 1" "\nresult b: " << b << "\nresult a: " << a << endl;

    cout << "\nTask 2" << endl;

    for(double x = -1; x <= 1; x = x + 0.2){
        double b2 = calculateB(x, y, z);
        double a2 = calculateA(x, y, z, b2);

        cout << "\nx: " << x << "\nresult b: " << b2 << "\nresult a: " << a2 << endl;
    }

    return 0;
}