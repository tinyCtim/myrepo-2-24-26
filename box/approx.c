#include <stdio.h>

// approx.c - lrb - 2/17/26

// this program approximates Euler's constant e
// using the limit definition

int main() {

 printf("\nEnter an integer, e.g. 10000 ");
 int num; scanf("%d", &num);
 double approx = 1;
 int work = 1;
 while (work < num) {
  approx *= (1 + 1./num);
  work++;
 }
 printf("\napproximation to e = %f ",approx);
 return(1);

}

