/*                                                                                                               
** ETNA PROJECT, 13/10/2018 by soubri_j                                                                          
** main                                                                                                
** File description:                                                                                             
**      Programs that reads parameters and capitalize it.
*/
#include <stdlib.h>
#include <stdio.h>

char *my_str_next_token(char *str, char *delim);
void my_putchar(char c);
void my_putstr(char *str);

int main(void)
{
	char *str1 = "Hello World!   such a nice day isn't it ?";
	char *str2 = "She put the lime____in the coconut----___------she drank 'em bot' up.";
	char *str3 = "";

	char *tmp = NULL;

	tmp = my_str_next_token(NULL, "");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, " !-");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(str3, "");
	printf("%s\n", tmp);
	free(tmp);

    tmp = my_str_next_token(str1, "$");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, "$");
	printf("%s\n", tmp);
	free(tmp);
	printf("start : \n");
	tmp = my_str_next_token(str1, " ");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(str2, "_-");
    printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, "_-");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, "_-");
	printf("%s\n", tmp);
	free(tmp);

    tmp = my_str_next_token(NULL, "_-");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, "_-");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(str1, " ");
    printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, " ");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, "_-)");
	printf("%s\n", tmp);
	free(tmp);
	tmp = my_str_next_token(NULL, "_-)");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(str2, "$");
	printf("%s\n", tmp);
	free(tmp);
    tmp = my_str_next_token(NULL, "$");
	printf("%s\n", tmp);
	free(tmp);

	printf("ETNA tests : \n");
	printf("%s\n", my_str_next_token(NULL, ""));
	printf("%s\n", my_str_next_token(NULL, " !-"));
	printf("%s\n", my_str_next_token("", ""));
	printf("%s\n", my_str_next_token("Hello Wordl!", " "));
	printf("%s\n", my_str_next_token(NULL, " "));
	printf("%s\n", my_str_next_token("  HELLO WORLD!lalala", " "));
	printf("%s\n", my_str_next_token(NULL, " !"));
	printf("%s\n", my_str_next_token("       Grizzly vs     Gorrilla   !   ", "vs"));
	printf("%s\n", my_str_next_token(NULL, "vs"));
	printf("%s\n", my_str_next_token(NULL, "vs"));
	printf("%s\n", my_str_next_token("Incoming Transmition#-$%##~_-_---All##%%$#your##$%%base&&$##are$###&belong$$##to***%%%###us**%%%###*###! Transmition Ended.", "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));
	printf("%s\n", my_str_next_token(NULL, "&~#$%-_/*"));

	printf("----lorem----\n");
	printf("%s\n", my_str_next_token(" Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Phasellus enim erat, vestibulum vel, aliquam a, posuere eu, velit. Nullam faucibus mi quis velit. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Maecenas lorem. Curabitur bibendum justo non orci. Sed ac dolor sit amet purus malesuada congue. Fusce suscipit libero eget elit. Aliquam erat volutpat. Aliquam ante. Praesent dapibus. Nulla non arcu lacinia neque faucibus fringilla. Duis ante orci, molestie vitae vehicula venenatis, tincidunt ac pede.   ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("%s\n", my_str_next_token(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("%s\n", my_str_next_token(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf("%s\n", my_str_next_token(NULL, "ABCDEFGHIJKLMNOPQRSTUVWXYZ"));

	printf("%s\n", my_str_next_token(" Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Phasellus enim erat, vestibulum vel, aliquam a, posuere eu, velit. Nullam faucibus mi quis velit. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Maecenas lorem. Curabitur bibendum justo non orci. Sed ac dolor sit amet purus malesuada congue. Fusce suscipit libero eget elit. Aliquam erat volutpat. Aliquam ante. Praesent dapibus. Nulla non arcu lacinia neque faucibus fringilla. Duis ante orci, molestie vitae vehicula venenatis, tincidunt ac pede.   ", " abcdefghijklmnopqrstuvwxyz.,"));
	printf("%s\n", my_str_next_token(NULL, " abcdefghijklmnopqrstuvwxyz.,"));
	printf("%s\n", my_str_next_token(NULL, " abcdefghijklmnopqrstuvwxyz.,"));
	printf("%s\n", my_str_next_token(NULL, " abcdefghijklmnopqrstuvwxyz.,"));
	printf("%s\n", my_str_next_token(NULL, " abcdefghijklmnopqrstuvwxyz.,"));
	printf("%s\n", my_str_next_token(NULL, " abcdefghijklmnopqrstuvwxyz.,"));

	printf("%s\n", my_str_next_token("lala   lala +++ lala --- lalala", "+")); 
	printf("%s\n", my_str_next_token(NULL, ""));
	return 0;
}