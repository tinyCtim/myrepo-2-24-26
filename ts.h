
/* ts.h - lrb */

#define MAXC 6000
#define MAXD 5000
#define EOF -1
#define NULL 0

char tt[MAXC]; /* tobee text buffer */
char ntt[MAXC]; /* new tobee text buffer */
char td[MAXD]; /* tobee dictionary buffer */
int endoffile;
char ver[5]; /* version */
int verbose,untran;
char tf[45],tdf[12],tdfnext[12];
/* tobee filename, dictionary filenames */ 
char crlf[3],lf[2];
char red,blue,white,lo,hi;
int vl,gi;
char msg[1040];
int fpd,fpm;

void main(int argc, char *argv[]);
void loaddic();
void trantobee();
void doit();
void i_error();
int index(char *s,char *t);

void putchar(char c);
int getchar();
int strlen(char *s);
int tolower(char c);
void exit();
int fopen(char *fn, char *fm);
char fgetc(int fp);
int fclose(int fp);
char *strcat(char *s1, char *s2);
char *strcpy(char *s1, char *s2);
int fputc(char c, int fp);
