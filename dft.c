#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 64  // Number of samples
#define PI 3.14159265358979323846

// from ChatGPT - 5/16/25 - lrb 

// Example function: sin(2 * PI * freq * t)
double sample_function(double t, double freq) {
    return sin(2 * PI * freq * t);
}

int main() {
    double signal[N];
    double real[N] = {0};
    double imag[N] = {0};
    double freq = 5.0; // Frequency of the sine wave in Hz
    double sample_rate = 64.0; // Sampling rate in Hz

    // Sample the function
    for (int n = 0; n < N; n++) {
        double t = n / sample_rate;
        signal[n] = sample_function(t, freq);
    }

    // Compute DFT
    for (int k = 0; k < N; k++) {
        for (int n = 0; n < N; n++) {
            double angle = 2 * PI * k * n / N;
            real[k] += signal[n] * cos(angle);
            imag[k] -= signal[n] * sin(angle);
        }
    }

    // Print the DFT result
    printf("k\tReal\tImag\tMagnitude\n");
    for (int k = 0; k < N; k++) {
        double magnitude = sqrt(real[k]*real[k] + imag[k]*imag[k]);
        printf("%d\t%.2f\t%.2f\t%.2f\n", k, real[k], imag[k], magnitude);
    }

    return 0;
}

