#include "M_Pav_AP-12_LW2.h"

#include <iostream>
#include <cmath>

using namespace std;

void calculateY(CalculationData& data) {
    double ax = data.a * data.x;

    if (ax >= 0 && ax <= 3) {
        data.y = sqrt(fabs(data.a + data.x)) + cbrt(fabs(ax)) + 1;
    }
    else if (ax < 0) {
        data.y = pow(2.718, pow(-data.x, 2) + data.a);
    }
    else if (ax > 3) {
        data.y = pow(data.x, cos(data.x)) + data.b / (pow(data.x, 2) + pow(data.a, 2));
    }
}

void start_LW_2(void) {
    CalculationData data;

    cout << "Enter values for parameters: " << endl;
    cout << "a = ";
    cin >> data.a;
    cout << "b = ";
    cin >> data.b;
    cout << "x = ";
    cin >> data.x;

    calculateY(data);

    cout << "Input data: a = " << data.a << ", b = " << data.b << ", x = " << data.x << endl;
    cout << "Result: y = " << data.y << endl;
}