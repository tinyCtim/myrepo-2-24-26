#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 10000

double fn(double x)
{
	return (
         (3*x + pow(9*x*x - 4*x*x*x,.5))/2);
}

int main(void)
{
    double x[MAX_POINTS], y[MAX_POINTS];
    int n = 0;
    int i;
    double dx, dy;
    double distance;
    double totalDistance = 0.0;
    for (i = 1; i <= 11; i++)
	{
		x[i]=1+(i-1)*.1;
		y[i]=fn(x[i]);
	}
    printf("Segment     Distance\n");
    printf("------------------------\n");

    for (i = 1; i < 11; i++)
    {
        dx = x[i + 1] - x[i];
        dy = y[i + 1] - y[i];
        distance = pow((dx * dx + dy * dy),.5);
        totalDistance += distance;
        printf("%3d -> %3d   %12.6f\n",
               i, i + 1, distance);
    }

    printf("------------------------\n");
    printf("Total Length = %.6f\n", totalDistance);

    return 0;
}
