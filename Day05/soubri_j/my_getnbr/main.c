#include <stdio.h>
int my_getnbr(char *str);
void display_result(char *str);

int main(void)
{
    display_result("42");
    display_result("666def123");
    display_result("-35kjb45");
    display_result("hgvj85khb");
    display_result("+-+4trois");
    display_result("--1");
    display_result(" --+90");
    display_result("--+90 90KL");
    display_result("--+789-90-87+34MLSDS ");
    display_result(NULL);
}

void display_result(char *str)
{
    printf("%s => %d\n", str, my_getnbr(str));
}