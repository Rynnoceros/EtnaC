#include <stdlib.h>
#include <stdio.h>
void my_putchar(char c);
void my_putstr(char *str);
char *my_strchr(char *str, char c);

int main(void)
{
	my_putstr(my_strchr("Hello World", 'o'));
	my_putchar('\n');
	my_putstr(my_strchr("plop", 'z'));
	my_putchar('\n');
	my_putstr("start\n");
	my_putstr(my_strchr("\\", 'a'));
	my_putchar('\n');
	my_putstr(my_strchr("a", 'a'));
	my_putchar('\n');
	my_putstr(my_strchr("a", 'b'));
	my_putchar('\n');
	my_putstr(my_strchr("ab", 'a'));
	my_putchar('\n');
	my_putstr(my_strchr("ab", 'b'));
	my_putchar('\n');
	my_putstr(my_strchr("ab", 'c'));
	my_putchar('\n');
	my_putstr(my_strchr("Hello World", 'H'));
	my_putchar('\n');
	my_putstr(my_strchr("Hello World", 'W'));
	my_putchar('\n');
	my_putstr(my_strchr("Hello World", 'o'));
	my_putchar('\n');
	my_putstr(my_strchr("Hello World", 'd'));
	my_putchar('\n');
	my_putstr(my_strchr("Hello World", 'a'));
	my_putchar('\n');
	printf("%s\n",my_strchr(NULL, '\x00'));
	my_putchar('\n');

	return 0;
}