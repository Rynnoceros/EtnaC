#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *my_strlowcase(char *str);

int main(void)
{
	char *str = "Hello World !";

	if ((str = strdup(str)) == NULL)
	return 1;

	printf("%s\n", my_strlowcase(str));
	printf("%s\n", my_strlowcase(NULL));

	free(str); // Free the strdup string
	return 0;
}