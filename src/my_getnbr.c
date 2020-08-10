 /*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns a number passed as string parameter
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    long result = 0;
    int bool = 0;
    int i = 0;

    if (str[0] == '-'){
        if (str[1] == '\0')
            return (0);
        bool = 1;
        i++;
    }
    for (; str[i]; i++){
        if (str[i] < '0' || str[i] > '9')
            break;
        result += (str[i] - 48);
        result *= 10;
        if (result > 2147483647
        || (bool == 1 && (result * -1) < -2147483648))
            return (0);
    }
    result /= 10;
    if (bool == 1)
        result *= -1;
    return (result);
}
