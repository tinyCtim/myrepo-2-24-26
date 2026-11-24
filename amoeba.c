#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*

amoeba.c - lrb - 9/25/12

An amoeba either dies, lives, splits into two or splits into three, each
with probability 0.25. It can be proved that (1.5)^n is the expected
number of amoebae after n generations and that a family tree becomes
extinct about 41.4 percent of the time. Starting w/ 1 amoeba, we let the
amoebae split for up to the specified number of generations.

Ref: http://primepuzzle.com/not.just.tiny.c/amoeba.html

*/

static int rnd_seed;

void usage() {
 printf("\namoeba.c - lrb - 11/24/2026");
 printf("\nUsage: amoeba [-b] [-g generations] [-s simulations] [-r seed]\n");
 exit(1);
 }

int main(int argc,char *argv[]) {
 unsigned int i,c,p,pp,psp,s,sims=10,gens=10,n,ptot,b=0;
 srand(time(NULL));
 for (i=1;i<argc;i++) {
  if (strcmp(argv[i],"-g")==0) {i++;gens=atoi(argv[i]);}
  else if (strcmp(argv[i],"-s")==0) {i++;sims=atoi(argv[i]);}
  else if (strcmp(argv[i],"-b")==0) b=1;
  else if (strcmp(argv[i],"-r")==0) {i++;rnd_seed=atoi(argv[i]);}
  else usage();
  }
 ptot=c=0;
 for (s=1;s<=sims;++s) {
  p=1;n=gens;
  while ((n--)*p) {
   psp=0;
   for (pp=1;pp<=p;++pp) psp+=rand()%4;
   p=psp;if (!p) ++c;
   }
  if (ptot+p<ptot) {
   printf("\nInteger limits exceeded; lower the number of simulations.\n");
   exit(1);
   }
  ptot+=p;
  if (!b) {
   printf("\nsimulation %u: population %u after ",s,p);
   printf("%u generation(s).",gens-n-1);
   }
  }
 printf("\n\n%u amoebae, on average, were living after ",ptot/sims);
 printf("%u generation(s).",gens);
 printf("\n%u",(unsigned int)pow(1.5,(double)gens));
 printf(" is the expected number of amoebae.");
 printf("\n\n%u populations died out.",c);
 printf("\n%u",(unsigned int)((double)sims*(pow(2,0.5)-1)));
 printf(" is the expected number to die out.\n");
 return(0);
 }
