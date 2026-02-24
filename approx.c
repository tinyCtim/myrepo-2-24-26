#include <stdio.h>

/*
 this program approximates Euler's number e
 from its limit definition
 lrb - 2/19/26
*/

// fixed bug in while condition - 2/20/26
// added noisy feature - 2/21/26
// removed noisy feature - 2/23/26

int main(void) {
 printf("\nEnter an integer, e.g. 1 or 4 or 100 or 10000000 "); // prompt user to enter a number
 int num; scanf("%d", &num); // read the number
 double approx = 1; // initialize the estimate
 int work = 1; // controls how long the loop lasts
 while (work++ <= num) { // main loop
  approx = approx * (1 + 1./num); // update the estimate
  } // end of loop
 printf("\napproximation to e = %20.15lf\n ",approx); // announce the result
 return(1); // to operating system
 }

