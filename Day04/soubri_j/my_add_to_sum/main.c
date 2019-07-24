#include <stdio.h>
int my_add_to_sum(int to_add);
void display_result(int to_add);

int main(void)
{
    display_result(2);
    display_result(5);
    display_result(-7);
    display_result(-10);
    display_result(100);
}

void display_result(int to_add)
{
    printf("Adding %d => result : %d\n", to_add, my_add_to_sum(to_add));
}