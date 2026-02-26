/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:13:20 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/26 16:07:45 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_monitor(t_data *data)
{
	int	i;
	
	while (get_alive(data) == 1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			if (check_if_one_died(data, i))
				return (1);
			i++;
		}
		if (all_ate_enough(data))
		{
			set_alive(data, 0);
			return (0);
		}

		usleep(1000);
	}
	return (0);
}

int	all_ate_enough(t_data *data)
{
	int	i;
	int meals;

	i = 0;
	if (data->nb_meal == -1)
		return (0);

	while (i < data->number_of_philo)
	{
		pthread_mutex_lock(&data->philos[i].meal_lock);
		meals = data->philos[i].nb_meals;
		pthread_mutex_unlock(&data->philos[i].meal_lock);

		if (meals < data->nb_meal)
			return (0);
		i++;
	}
	return (1);
}

void	set_alive(t_data *data, int n)
{
	pthread_mutex_lock(&data->alive_lock);
	data->alive = n;
	pthread_mutex_unlock(&data->alive_lock);
}

int	check_if_one_died(t_data *data, int i)
{
	long	last_meal_time;
	long	current_time;
	long	elapsed;
	t_philo	*philos;

	philos = &data->philos[i];
	current_time = get_time();

	pthread_mutex_lock(&philos->meal_lock);
	last_meal_time = philos->last_meal;
	pthread_mutex_unlock(&philos->meal_lock);

	elapsed = current_time - last_meal_time;
	if (elapsed > data->time_to_die)
	{
		set_alive(data, 0);
		pthread_mutex_lock(&data->print_lock);
		printf("%ld %d died\n", get_time() - data->start_time,
			philos->id);
		pthread_mutex_unlock(&data->print_lock);
		return (1);
	}
	return (0);
}
