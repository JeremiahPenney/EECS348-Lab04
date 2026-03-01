#include <stdio.h>

int main(void)
{
    int score;

    while (1) // this is just an inf loop so the program keeps going until the user enters 0 or 1 to stop it from running
    {
        //// just askign user for the score each time loop is ran

        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
            break;

        printf("Possible combinations of scoring plays if a team’s score is %d:\n", score);

        // just declare da loop variables here so it works on other c comp also
        int a, b, c, d, e;

        for (a = 0; a <= score / 8; a++) // just the math or you can think of it as an inf formula based on the user but its really simple logically
            for (b = 0; b <= score / 7; b++)
                for (c = 0; c <= score / 6; c++)
                    for (d = 0; d <= score / 3; d++)
                        for (e = 0; e <= score / 2; e++)
                        {
                            int sum = 8 * a + 7 * b + 6 * c + 3 * d + 2 * e;

                            if (sum != score)
                                continue;

                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   a, b, c, d, e);
                        }
    }

    return 0;
}