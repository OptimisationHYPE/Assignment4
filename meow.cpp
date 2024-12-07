#include <bits/stdc++.h>

using namespace std;

// Task 1: Bisection Method
// Function from task
double f1(double x) {
    return pow(x, 3) - 6 * pow(x, 2) + 11 * x - 6;
}

double bisection(double a, double b, double epsilon) {
    double c = (a + b) / 2.0;
    while (fabs(f1(c)) >= epsilon){
        if (f1(a) * f1(c) < 0) {
            b = c;
        } 
        else {
            a = c;
        }

        c = (a + b) / 2.0;
    }
    return c;
}

// Task 2: Golden Section Method
// Function from task
double f2(double x) {
    return pow(x - 2, 2) + 3;
}

double goldenSection(double a, double b, double epsilon) {
    const double phi = (1 + sqrt(5)) / 2.0; // Golden ratio
    double x1 = b - (b - a) / phi;
    double x2 = a + (b - a) / phi;

    while ((b - a) > epsilon) {
        if (f2(x1) < f2(x2)) {
            b = x2;
            x2 = x1;
            x1 = b - (b - a) / phi;
        } 
        else {
            a = x1;
            x1 = x2;
            x2 = a + (b - a) / phi;
        }
    }

    return (a + b) / 2.0;
}

// Task 3: Gradient Ascent Method
// Function from task
double f3(double x) {
    return -pow(x, 2) + 4 * x + 1;
}

double df3(double x) {
    return -2 * x + 4;
}

double gradientAscent(double x0, double alpha, int iterations) {
    double x = x0;
    for (int i = 0; i < iterations; i++) {
        x += alpha * df3(x);
    }
    return x;
}

int main() {
    // Bisection Method
    double a, b, epsilon;
    cin >> a >> b >> epsilon;
    cout << "Task 1: Bisection Method" << endl;
    double root = bisection(a, b, epsilon);
    cout << "Approximate root: " << setprecision(10) << root << endl;

    // Golden Section Method
    cin >> a >> b >> epsilon;
    cout << "\nTask 2: Golden Section Method" << endl;
    double xmin = goldenSection(a, b, epsilon);
    cout << "Approximate xmin: " << setprecision(10) << xmin << endl;
    cout << "f(xmin): " << f2(xmin) << endl;

    // Gradient Ascent Method
    double x0, alpha;
    int iterations;
    cin >> x0 >> alpha >> iterations;
    cout << "\nTask 3: Gradient Ascent Method" << endl;
    double xmax = gradientAscent(x0, alpha, iterations);
    cout << "Approximate xmax: " << setprecision(10) << xmax << endl;
    cout << "f(xmax): " << f3(xmax) << endl;

    return 0;
}
