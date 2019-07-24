#include <stdio.h>
int my_getnbr_base(char *str, char *base);
void display_result(char *str, char *base);

int main(void)
{
    display_result("42", "0123456789");
    display_result("111", "01");
    display_result("-42","0123456789");
    display_result("145THE","0123456789");
    display_result("000","01");
    display_result("5464E","0123456789ABCDEF");
    display_result("))!", "!)\\n");
    display_result("+--))!", "!)\\n");
    display_result("+++))!", "!)\\n");
    display_result("-----+))!", "!)\\n");
    display_result("--   ---+))!", "!)\\n");
    display_result(NULL, NULL);
    display_result(NULL, "ABC");
    display_result("ABC", NULL);
    display_result("145THE","0123456789+");
}

void display_result(char *str, char *base)
{
    printf("%s (%s) => %d\n", str, base, my_getnbr_base(str, base));
}