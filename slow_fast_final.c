
/*

Two runners compete in a 5K race. They go out 1.55 miles, turn around,
and come back to the start. The fast runner runs at a 5.33 minutes per
mile pace. At the 1 mile mark, the two runners cross paths, the fast
runner having turned at the turnaround and is coming back. Please write
a program in C that shows distance travelled and time in minutes by
minute of the event, ending with the slow runner finishing the race.

Started with ChatGPT - modified by lrb - 1/18/26

*/

#include <stdio.h>

int main(void)
{
    const double RACE_DISTANCE = 3.10;

    const double FAST_PACE = 5.33;          // minutes per mile
// the slow pace is determined from the crossing at the 1 mile mark
    const double SLOW_PACE = 11.193;        // minutes per mile

    double fastDist = 0.0;
    double slowDist = 0.0;

    double fastStep = 1.0 / FAST_PACE;
    double slowStep = 1.0 / SLOW_PACE;

    int minute = 0;
    int flag = 0;       // flag is "raised" when the slow runner finishes

    printf("Minute-by-minute race history\n");
    printf("--------------------------------------------\n");
    printf("Min | Fast Runner (mi)   | Slow Runner (mi)\n");
    printf("--------------------------------------------\n");

    while (flag == 0)
    {
        printf("%3d | %6.2f             | %6.2f\n",
               minute, fastDist, slowDist);

        // Advance one minute
        minute++;

        // Fast runner movement
        fastDist += fastStep;
        if (fastDist > RACE_DISTANCE)    // adjust for overrun
              fastDist = RACE_DISTANCE;

        // Slow runner movement
        slowDist += slowStep;
        if (slowDist > RACE_DISTANCE) {
             slowDist = RACE_DISTANCE;flag=1; // adjust for overrun, "raise" flag
             printf("%3d | %6.2f             | %6.2f\n", // print last line
               minute, fastDist, slowDist);
             }
    }

    return 0;
}

