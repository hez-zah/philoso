#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define RED "\033[0;31m"

typedef struct s_fork
{
    int right_fork;
    int left_fork;
}t_fork;

typedef struct s_action
{
    int take_fork;
    int eat;
    int sleep;
    int deat;
}t_action;

typedef struct s_philo
{
    pthread_t       num_philo;
    int             index_philo;
    int             tm_die;
    int             tm_eat;
    int             tm_sleep;
    int             nb_tm_philo_eat;
    long            time;
    t_fork          fork;
    t_action        action;
    struct s_philo  *next;
}t_philo;

void    *ft_memset(void *b, int c, size_t len);
long    ft_atoi(char *str);
int     check(int ac, char **av);
t_philo *linkd_philo(t_philo *philo, int ac, char **av);

#endif
