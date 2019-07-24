char my_prev_char(char c);
void my_putchar(char c);

int main(void)
{
    my_putchar(my_prev_char('a'));
    my_putchar(my_prev_char('c'));
    my_putchar(my_prev_char('z'));
    my_putchar(my_prev_char('A'));
    my_putchar(my_prev_char('N'));
    my_putchar(my_prev_char('Z'));
    my_putchar(my_prev_char('{'));
    my_putchar(my_prev_char('0'));
}