/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:12:56 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/26 16:13:04 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_a_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->next_fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork);
		print_state(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->fork);
		print_state(philo, "has taken a fork");
		pthread_mutex_lock(philo->next_fork);
		print_state(philo, "has taken a fork");
	}
}
void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->meal_lock);
}

void	*routine(void *arg)
{
	t_philo *philo;
	
	philo = (t_philo *)arg;//cast pentru argumente
	if (philo->id % 2 == 0)
		usleep(1000);
	if (philo->data->number_of_philo == 1)
	{
		print_state(philo, "has taken a fork");
		precise_sleep(philo->data->time_to_die, philo->data);
		return (NULL);
	}
	while (get_alive(philo->data))
	{
		take_a_fork(philo);
		print_state(philo, "is eating");
		update_last_meal(philo);
		precise_sleep(philo->data->time_to_eat, philo->data);

		release_forks(philo);
		
		print_state(philo, "is sleeping");
		precise_sleep(philo->data->time_to_sleep, philo->data);
		print_state(philo, "is thinking");
	}
	return (NULL);
}
