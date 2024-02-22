#include <stdio.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to perform Newton's Backward Interpolation
float newtonBackwardInterpolation(int n, float x[], float y[], float x0) {
    float y0 = y[n-1], u = (x0-x[n-1])/(x[n-1]-x[n-2]);
    float backward[n-1][n-1];

    // Calculating the backward difference table
    for (int j = 0; j < n-1; j++) {
        for (int i = n-1; i > j; i--) {
            if (j == 0) {
                backward[i-1][j] = y[i] - y[i-1];
            } else {
                backward[i-1][j] = backward[i][j-1] - backward[i-1][j-1];
            }
        }
    }

    // Applying Newton's Backward Interpolation formula
    for (int j = 1; j < n; j++) {
        y0 += (u*backward[n-1-j][j-1])/factorial(j);
        u *= (x0-x[n-1-j])/(x[n-j]-x[n-1-j]);
    }

    return y0;
}

int main() {
    int n; // Number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n]; // Arrays to store the data points

    // Taking input for x and y arrays
    for (int i = 0; i < n; i++) {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    // Sorting the x array in ascending order
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (x[j] > x[j+1]) {
                float temp = x[j];
                x[j] = x[j+1];
                x[j+1] = temp;

                temp = y[j];
                y[j] = y[j+1];
                y[j+1] = temp;
            }
        }
    }

    float x0; // Value of x for which we need to find y
    printf("Enter the value of x for which y is to be found: ");
    scanf("%f", &x0);

    // Calling the newtonBackwardInterpolation function
    float y0 = newtonBackwardInterpolation(n, x, y, x0);

    // Printing the result
    printf("The value of y at x = %.2f is %.2f\n", x0, y0);

    return 0;
}