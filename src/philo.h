#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_data t_data;

typedef struct	s_philo
{
	pthread_t	philo_thread;
	int			id;
	int			nb_meals;
	long		last_meal;//ca sa stiu timplul la care el a mancat ultima dataa si sa fac calculele ca sa vad daca moare sau nu pt ca daca get_time() - last meal > time to die !!!moare

	pthread_mutex_t fork;
	pthread_mutex_t *next_fork;
	pthread_mutex_t	meal_lock;
	t_data		*data;
	
}	t_philo;

typedef struct	s_data
{
	int		alive;
	int		number_of_philo;

	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;

	long	start_time;
	int		nb_meal;// sa stiu daca moare in caz ca  [number_of_times_each_philosopher_must_eat]
	int		all_ate;

	pthread_mutex_t	alive_lock;
	pthread_mutex_t	print_lock;
	
	t_philo	*philos;

}	t_data;

int			parse_args(t_data *data, int argc, char **argv);

long int	get_time(void);
int			get_alive(t_data *data);
void		precise_sleep(long ms, t_data *data);
void		print_state(t_philo *philo, char *msg);

int			init_data(t_data *data);
int			init_philosophers(t_data *data);

int			is_digit(int argc, char **argv);
long		ft_atoi(const char *nptr);

void		take_a_fork(t_philo *philo);
void		release_forks(t_philo *philo);
void		*routine(void *arg);

int			create_threads(t_data *data);
int			join_threads(t_data *data);

void		cleanup(t_data *data);

void		set_alive(t_data *data, int n);
int			check_if_one_died(t_data *data, int i);
int			all_ate_enough(t_data *data);
int			death_monitor(t_data *data);

#endif