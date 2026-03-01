#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846
#define TERMS 10  // Number of sine terms in the series
#define STEP 0.1  // Step size for plotting

// Precomputed Fourier sine coefficients for x^3 over [-p, p]
double compute_bn(int n) {
    if (n % 2 == 0) return 0.0;  // Even terms vanish due to odd symmetry

    // b_n = 6 * ((-1)^n) / n^3 for x^3 over [-p, p]
    double sign = (n % 4 == 1) ? 1.0 : -1.0;
    return 6.0 * sign / (n * n * n);
}

double approximate_x3(double x) {
    double sum = 0.0;
    for (int n = 1; n <= TERMS; n++) {
        double bn = compute_bn(n);
        sum += bn * sin(n * x);
    }
    return sum;
}

int main() {
    printf("x\tApprox\tActual\n");
    for (double x = -PI; x <= PI; x += STEP) {
        double approx = approximate_x3(x);
        double actual = x * x * x;
        printf("% .2f\t% .5f\t% .5f\n", x, approx, actual);
    }
    return 0;
}

