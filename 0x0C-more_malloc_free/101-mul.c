#include <stdio.h>
#include <stdlib.h>

int str_len(char *str);
void print_error(void);

/**
 * main - multiplies two positive numbers
 *
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char **argv)
{
    int len1, len2, len_res, carry, i, j, res;
    int *result;
    char *num1, *num2;

    if (argc != 3)
        print_error();

    num1 = argv[1];
    num2 = argv[2];

    len1 = str_len(num1);
    len2 = str_len(num2);
    len_res = len1 + len2;
    result = calloc(len_res, sizeof(int));
    if (!result)
        return (98);

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            res = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
            carry = res / 10;
            result[i + j + 1] = res % 10;
        }
        result[i + j + 1] += carry;
    }

    i = 0;
    while (i < len_res - 1 && result[i] == 0)
        i++;

    for (; i < len_res; i++)
        printf("%d", result[i]);
    printf("\n");

    free(result);
    return (0);
}

/**
 * str_len - calculates the length of a string
 *
 * @str: pointer to the string
 *
 * Return: length of the string
 */
int str_len(char *str)
{
    int len = 0;

    while (*str++)
        len++;

    return (len);
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
    printf("Error\n");
    exit(98);
}
