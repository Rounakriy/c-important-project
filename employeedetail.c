#include <stdio.h>

struct employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    struct employee e;

    e.id = 101;
    e.salary = 25000;

    printf("enter name: ");
    scanf("%19s", e.name);

    printf("ID = %d\n", e.id);
    printf("name = %s\n", e.name);
    printf("salary = %.2f\n", e.salary);

    return 0;
}
