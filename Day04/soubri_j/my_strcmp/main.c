#include <stdio.h>
int my_strcmp(char *s1, char *s2);
void display_result(char *s1, char *s2);

int main(void)
{
    display_result(NULL,NULL);
    display_result(NULL,"");
    display_result("",NULL);
    display_result("","");
    display_result("a","a");
    display_result("abcde","abcde");
    display_result("int main(voi){ write (1, str,1); }","int main(voi){ write (1, str,1); }");
    display_result("abcd","int main(voi){ write (1, str,1); }");
    display_result("int main(voi){ write (1, str,1); }","abc");
    display_result("$/djksqjdkq-^","$/djksqjdkq-^");
    display_result("abc","$/djksqjdkq-^");
    display_result("$/djksqjdkq-^","abc");
    display_result("abcdef","abcdefg");
    display_result("abcdefg","abcdef");
    display_result("abcdefg","abcdef");
}

void display_result(char *s1, char *s2)
{
    printf("Comparing %s|%s : %d\n", s1, s2, my_strcmp(s1, s2));
}