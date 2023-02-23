#include <stdio.h>

/**
* main - causes an infinite loop
* Return: 0
*/

int main(void)
{
        int i;

        printf("Infinite loop incoming :(\n");

        i = 0;

        while (i < 10)
        {
                putchar(i + '0'); // add '0' to convert i to ASCII value
                i++; // add increment statement
        }

        printf("\nInfinite loop avoided! \\o/\n");

        return (0);
}
