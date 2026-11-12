#include <stdio.h>

int main()
{
    int month, year;
    int days, startDay;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12)
    {
        printf("Invalid month!");
        return 0;
    }

    // Find number of days
    switch (month)
    {
    case 2:
        days = 28;
        if ((year % 400 == 0) ||
            (year % 4 == 0 && year % 100 != 0))
            days = 29;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;

    default:
        days = 31;
    }

    // Calculate starting day
    int d = 1, m = month, y = year;

    if (m < 3)
    {
        m += 12;
        y--;
    }

    int k = y % 100;
    int j = y / 100;

    startDay = (d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    startDay = (startDay + 6) % 7;

    // Print calendar
    printf("\n      %d / %d\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (int i = 0; i < startDay; i++)
    {
        printf("    ");
    }

    for (int date = 1; date <= days; date++)
    {
        printf("%3d ", date);

        if ((date + startDay) % 7 == 0)
            printf("\n");
    }

    printf("\n");

    return 0;
}