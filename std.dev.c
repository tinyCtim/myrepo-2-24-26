
/*
 * C program to input real numbers and find the mean, variance
 * and standard deviation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXSIZE 1000

// execute ./st.dev -i file

int main(int argc, char *argv[])
{
    float x[MAXSIZE];
    int  i, n;
    float average, variance, std_deviation, sum = 0, sum1 = 0;
    FILE *fp;
    char file[30];
    if (strcmp("-i",argv[1])==0) strcpy(file,argv[2]);
    fp=fopen(file,"r");
    fscanf(fp,"%d", &n);  // get number of data values
    for (i = 0; i < n; i++) // read 'em in
    {
        fscanf(fp,"%f", &x[i]);
    }
    /*  Compute the sum of all elements */
    for (i = 0; i < n; i++)
    {
        sum = sum + x[i];
    }
    average = sum / (float)n;
    /*  Compute variance and standard deviation  */
    for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((x[i] - average), 2);
    }
    variance = sum1 / (float)n;
    std_deviation = sqrt(variance);
    printf("Average of all elements = %.2f\n", average);
    printf("variance of all elements = %.2f\n", variance);
    printf("Standard deviation = %.2f\n\n", std_deviation);
    fclose(fp);
    exit(0);
}
