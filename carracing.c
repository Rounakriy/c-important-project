#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int carPosition = 10;
int enemyPosition = 5;
int enemyLane = 10;
int score = 0;
int gameOver = 0;

void drawRoad()
{
    system("cls");

    printf("\n       CAR RACING GAME\n");
    printf("       Score: %d\n\n", score);

    for (int i = 0; i < 20; i++)
    {
        printf("       ");

        for (int j = 0; j < 21; j++)
        {
            if (j == 0 || j == 20)
                printf("|");
            else if (i == enemyPosition && j == enemyLane)
                printf("E");
            else if (i == 18 && j == carPosition)
                printf("A");
            else if (j == 10)
                printf(".");
            else
                printf(" ");
        }

        printf("\n");
    }

    printf("\nA = Left | D = Right | X = Exit\n");
}

void input()
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == 'a' || key == 'A')
        {
            if (carPosition > 2)
                carPosition--;
        }

        if (key == 'd' || key == 'D')
        {
            if (carPosition < 18)
                carPosition++;
        }

        if (key == 'x' || key == 'X')
            gameOver = 1;
    }
}

void logic()
{
    enemyPosition++;

    if (enemyPosition == 18 && enemyLane == carPosition)
    {
        gameOver = 1;
    }

    if (enemyPosition >= 20)
    {
        enemyPosition = 0;
        enemyLane = 2 + rand() % 17;
        score += 10;
    }
}

int main()
{
    srand(time(0));

    while (!gameOver)
    {
        drawRoad();
        input();
        logic();

        Sleep(150);
    }

    system("cls");

    printf("\n      GAME OVER!\n");
    printf("      Final Score: %d\n", score);

    return 0;
}