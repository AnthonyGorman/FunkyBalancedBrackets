#include "solution.c"
#define MAX_LIMIT 1000
int main()
{
    char brackets[MAX_LIMIT];
    fgets((char*)brackets, MAX_LIMIT, stdin);
    size_t ln = strlen(brackets)-1;
    if (brackets[ln] == '\n')
        brackets[ln] = '\0';
    printf("%s\n", isBalanced(brackets));
    return 0;
}