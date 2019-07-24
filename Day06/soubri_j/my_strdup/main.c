#include <stdio.h>
#include <stdlib.h>
char *my_strdup(char *str);
void my_putchar(char c);

int main(void)
{
    char *string = NULL;
    char *dup_string = NULL;

    string = malloc(sizeof(char) * 40);
    string = "You are the best programmer of the world";
    printf("string : %s\n", string);
    printf("duplicate string before : %s\n", dup_string);
    dup_string = my_strdup(string);
    printf("duplicate string after : %s\n", dup_string);
    dup_string = my_strdup("Hello world");
    printf("duplicate string after : %s\n", dup_string);
    dup_string = my_strdup(NULL);
    printf("duplicate string after : %s\n", dup_string);

    string = malloc(sizeof(char) * 1000);
    string = my_strdup("abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    dup_string = my_strdup(string);
    printf("duplicate string after : %s\n", dup_string);
    
    int cpt = 0;
    while (dup_string[cpt] != '\0') {
        my_putchar(dup_string[cpt]);
        ++cpt;
    }

    printf("%d\n", dup_string[++cpt]);
    printf("%d\n", dup_string[++cpt]);
    printf("%d\n", dup_string[++cpt]);
    printf("%d\n", dup_string[++cpt]);
    my_putchar('\n');
}