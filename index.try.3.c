
// https://www.tutorialkart.com/c-programming/c-program-find-index-of-substring-in-string/#gsc.tab=0

// 8/30/24 - lrb - to use in secret six challenge on !jtc

/* 
8/31/24 - lrb - beefed up "dictionary", added display of program name etc.
added user input for word number 

9/3/24 - switched order to "key","definition" 
*/

#include <stdio.h>
#include <string.h>
 
int main() {
	printf("\nindex.try.3.c - lrb - 9/3/24\n\n");
	int k;
	char str[100] = "123apple456banana777orange314159pineapple2718281828endive1414Root";
	while (1) {
		printf("\nenter word number (0 thru 5) : ");
		scanf("%i", &k);
		if (k >= 0 && k <= 5) break;
		}
	char substr[6][20] = {"123","456","777","314159","2718281828","1414"};
	char substrw[20] = "";
	strcpy(substrw, substr[k]);
	char definition[20] = "";
	int index = -1;
	int i,j;
	for (i = 0; str[i] != '\0'; i++) {
		index = -1;
		for (j = 0; substrw[j] != '\0'; j++) {
			if (str[i + j] != substrw[j]) {
				index = -1;
				break;
				}
			index = i;
			}
		if (index != -1) {
			break;
			}
	}
//  printf("%d", j);
//  printf("%d", index);
	index = index + j;
//  printf("%d", index);
	j = 0;
	while( (str[index] >= 'a' && str[index] <= 'z') || (str[index] >= 'A' && str[index] <= 'Z') ) {
//      printf("%c", str[index]);
		definition[j] = str[index];
		index++; j++;
		}
	printf("definition for %s is : %s\n", substrw, definition);
	return 0;
}
