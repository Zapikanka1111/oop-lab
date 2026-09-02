#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x = 1, y = 2, z = 3;
    double  b = ((y + atan(pow((fabs(pow(x, 2) + z)), 1/3)))/(2*z + x + pow(sin(pow(y, 3)), 2)))+exp(-((x + z)/(x +1)));

    double  a = (pow((1+y), 2))*(((pow((fabs(x+y)), 0.3))/pow(b, 2) + z)/(1+exp(-(x-y)) + pow(fabs(y), 0.43)));

    cout << "task 1" "\nresult b: " << b << "\nresult a: " << a << endl;

    a = 0;
    b = 0;

    cout << "\nTask 2" << endl;

    for(double x = -1; x <= 1; x = x + 0.2){
        b = ((y + atan(pow((fabs(pow(x, 2) + z)), 1/3)))/(2*z + x + pow(sin(pow(y, 3)), 2)))+exp(-((x + z)/(x +1)));

        a = (pow((1+y), 2))*(((pow((fabs(x+y)), 0.3))/pow(b, 2) + z)/(1+exp(-(x-y)) + pow(fabs(y), 0.43)));

        cout << "\nx: " << x << "\nresult b: " << b << "\nresult a: " << a << endl;
    }

    return 0;
}
