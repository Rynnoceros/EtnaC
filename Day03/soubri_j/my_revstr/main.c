#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *my_revstr(char *str);

int main(void)
{
	char *str = "Hello World !";

	if ((str = strdup(str)) == NULL)
	return 1;

	printf("%s\n", my_revstr(str));
	/*printf("%s\n", my_revstr("a"));
	printf("%s\n", my_revstr("ab"));
	printf("%s\n", my_revstr("abc"));
	printf("%s\n", my_revstr("abcd"));
	printf("%s\n", my_revstr("abcde"));
	printf("%s\n", my_revstr("Lorem ipsum dolor sit amet"));*/
	char *str2 = "void my_putchar(char c) { write(1, &c, 1); }";
	char *str3 = "";
	if ((str2 = strdup(str2)) == NULL)
	return 1;
	if ((str3 = strdup(str3)) == NULL)
	return 1;
	printf("%s\n", my_revstr(str2));
	printf("%s\n", my_revstr(str3));
	printf("reverse NULL:%s\n", my_revstr(NULL));
	free(str); // Free the strdup string
	free(str2);
	return 0;
}