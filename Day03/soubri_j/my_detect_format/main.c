#include <stdlib.h>
void my_detect_format(char *str);

int main(void)
{
	my_detect_format("0 1234 abcd ab12");
	my_detect_format(" 0   4567  \t\t fghi\tfg45  ");
    my_detect_format(" 0 toto76  \n\n $^/ \tfg45  ");
	my_detect_format(NULL);
	return 0;
}