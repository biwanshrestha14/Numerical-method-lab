#include <stdio.h>
#include <math.h>
// Function to integrate
double function(double x) {
return (4 * exp(x)/(1+pow(x,3))); // Replace with your desired function
}
// Trapezoidal rule for numerical integration
double trapezoidalRule(double a, double b, int n) {
double h = (b - a) / n; // Step size
double sum = (function(a) + function(b)) / 2.0; //finding sum of 1st term and last term
for (int i = 1; i < n; i++) {
double x = a + i * h;
sum += function(x); //finding sum of intermediate terms.
}
return h * sum;
}
int main() {
double a = 0.0; // Lower limit of integration
double b = 2.0; // Upper limit of integration
int n = 100; // Number of subintervals
double result = trapezoidalRule(a, b, n);
printf("Numerical integration result: %lf\n", result);
return 0;
}