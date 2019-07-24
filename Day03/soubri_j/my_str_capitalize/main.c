#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *my_str_capitalize(char *str);

int main(void)
{
	char *str = "hElLo worDl !jojo\ttutu\ntata";
	char *str2 = "AdsdsHJ nbcLJHndghJ kLLLk";

	if ((str = strdup(str)) == NULL)
	return 1;
	if ((str2 = strdup(str2)) == NULL)
	return 1;

	printf("%s\n", my_str_capitalize(str));
	printf("NULL:%s\n", my_str_capitalize(NULL));
	printf("%s\n", my_str_capitalize(str2));

	free(str); // Free the strdup string
	free(str2);
	return 0;
}