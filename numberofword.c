#include <stdio.h>
#include <string.h>

int main()
{
    char name[100];

    printf("enter full name:");
    fgets(name, sizeof(name), stdin);

    name[strcspn(name, "\n")] = '\0';
    printf("length of your name = %1u", strlen(name));

    return 0;
}