#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *my_strupcase(char *str);

int main(void)
{
	char *str = "Hello World !";

	if ((str = strdup(str)) == NULL)
	return 1;

	printf("%s\n", my_strupcase(str));
	printf("%s\n", my_strupcase(NULL));

	free(str); // Free the strdup string
	return 0;
}