#include <stdio.h>
#define get(s) #s
 
int main()
{
    char str[] = get(GeeksQuiz);
    printf("%s\n", str);
    return 0;
}
