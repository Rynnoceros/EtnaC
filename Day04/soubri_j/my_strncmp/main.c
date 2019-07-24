#include <stdio.h>
int my_strncmp(char *s1, char *s2, int n);
void display_result(char *s1, char *s2, int n);

int main(void)
{
    display_result(NULL,NULL,3);
    display_result(NULL,"",-1);
    display_result("",NULL,0);
    display_result("","",3);
    display_result("a","a",3);
    display_result("abcde","abcde",-1);
    display_result("int main(voi){ write (1, str,1); }","int main(voi){ write (1, str,1); }",0);
    display_result("abcd","int main(voi){ write (1, str,1); }", 0);
    display_result("int main(voi){ write (1, str,1); }","abc", -1);
    display_result("$/djksqjdkq-^","$/djksqjdkq-^", 3);
    display_result("abc","$/djksqjdkq-^", 3);
    display_result("$/djksqjdkq-^","abc", 1);
    display_result("abcdef","abcdefg",7);
    display_result("abcdefg","abcdef",7);
    display_result("abcdefg","abcdef",3);

    display_result("0123456789","0123_56789",4);
    display_result("0123456789","0123456789A",10);
    display_result("0","0123456789A",1);
    display_result("abcdefghijklmnopqr","abcdefghijklmnopqrstuvwxyz",18);
}

void display_result(char *s1, char *s2, int n)
{
    printf("Comparing %d chars %s|%s : %d\n", n, s1, s2, my_strncmp(s1, s2, n));
}