char my_next_char(char c);
void my_putchar(char c);

int main(void)
{
    my_putchar(my_next_char('a'));
    my_putchar(my_next_char('c'));
    my_putchar(my_next_char('z'));
    my_putchar(my_next_char('A'));
    my_putchar(my_next_char('N'));
    my_putchar(my_next_char('Z'));
    my_putchar(my_next_char('{'));
    my_putchar(my_next_char('0'));
}