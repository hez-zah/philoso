#include "philo.h"

int main(int ac, char **av)
{
    t_philo *philo;

    if (!check(ac, av))
        return (0);
    philo = linkd_philo(philo, ac, av);
}
