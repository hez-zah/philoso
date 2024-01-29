#include "philo.h"

int check(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    if (ac != 6 && ac != 5)
    {
        printf("\e[0;38;5;199mERROR: The number of argments must be 4 or 5\n");
        exit(1);
    }
    while (av[++i])
    {
        j = -1;
        while (av[i][++j])
        {
            if ((av[i][j] < '0' || av[i][j] > '9'))
            {
                printf("\033[0;31mInvalid Arguments\n");
                exit(1);
            }
        }
    }
    return (1);
}
