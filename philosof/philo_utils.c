#include "philo.h"

int check_aspects(long result)
{
    if (result > 2147483647 || result < 0)
        return (0);
    return (1);
}

long ft_atoi(char *str)
{
    int signe;
    long result;

    signe = 1;
    result = 0;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-')
        signe = -1;
    if (*str == '-' || *str == '+')
        str++;
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    if (*str == '+' || *str == '-' || !check_aspects(result * signe))
    {
        printf("\033[0;31mInvalid Arguments\n");
        exit(1);
    }
    return (result * signe);
}

t_philo *add_new(int index, int ac, char **av)
{
    t_philo *new_philo;

    new_philo = (t_philo *)malloc(sizeof(t_philo));
    new_philo->index_philo = index;
    new_philo->tm_die = ft_atoi(av[2]);
    new_philo->tm_eat = ft_atoi(av[3]);
    new_philo->tm_sleep = ft_atoi(av[4]);
    if (ac == 6)
        new_philo->nb_tm_philo_eat = ft_atoi(av[5]);
    new_philo->time = 0;
    new_philo->fork.right_fork = 1;
    new_philo->fork.left_fork = 0;
    new_philo->action.take_fork = 0;
    new_philo->action.eat = 0;
    new_philo->action.sleep = 0;
    new_philo->action.deat = 0;
    return (new_philo);
}

t_philo *add_back_new(t_philo *philo ,int i, int ac, char **av)
{
    t_philo *tmp;
    t_philo *b;

    b = add_new(i, ac, av);
    if (!philo)
        philo = b;
    else
    {
        tmp = philo;
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = b;
    }
    return (philo);
}

t_philo *linkd_philo(t_philo *philo, int ac, char **av)
{
    int i;
    int     nb_philo;

    i = -1;
    nb_philo = ft_atoi(av[1]);
    philo = NULL;
    while (++i < nb_philo)
        philo = add_back_new(philo , i, ac, av);
    return (philo);
}