#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

double calculateFunction(double x, double a, double b) {
    return (pow(x, a / b) - cbrt((x + b) / a)) / (1.1 + pow(cos(a * x), 2));
}

void processResults(const std::vector<double>& results, int& count, double& product) {
    count = 0;
    product = 1.0;

    for (double y : results) {
        if (y < 10) {
            count++;
            product *= y;
        }
    }

    if (count == 0) {
        product = 0;
    }
}

void start_LW_3(void) {
    const double xStart = 6.8;
    const double xEnd = 20.8;
    const double h = 1.0;
    const double a = 3.5;
    const double b = 6.4;

    std::vector<double> results;
    std::cout << std::fixed << std::setprecision(4);

    std::cout << "Табулювання функції:" << std::endl;
    std::cout << "  x\t\t  y" << std::endl;
    for (double x = xStart; x <= xEnd; x += h) {
        double y = calculateFunction(x, a, b);
        results.push_back(y);
        std::cout << x << "\t\t" << y << std::endl;
    }

    int count;
    double product;
    processResults(results, count, product);

    std::cout << "\nКількість значень y: " << count << std::endl;
    if (count > 0) {
        std::cout << "Добуток значень y: " << product << std::endl;
    }
    else {
        std::cout << "Жодне значення не задовольняє умову y < 10." << std::endl;
    }

}
