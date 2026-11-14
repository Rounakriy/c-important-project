#include <stdio.h>
int main()
{
    int sum = 0;
    for (int i = 9; i <= 99; i++)
    {
        sum += i;
    }

    printf("sum is %d", sum);
    return 0;
}