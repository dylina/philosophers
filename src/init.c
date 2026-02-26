/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:44:12 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/26 17:17:46 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philosophers(t_data *data)
{
	int	i;
	int	next_index;

	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].nb_meals = 0;
		data->philos[i].last_meal = data->start_time;
		data->philos[i].data = data;
		if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&data->philos[i].meal_lock, NULL) != 0)
		{
			pthread_mutex_destroy(&data->philos[i].fork);
			return (1);
		}
		next_index = (i + 1) % data->number_of_philo;
		data->philos[i].next_fork = &data->philos[next_index].fork;
		i++;
	}
	return (0);
}

int	init_data(t_data *data)
{
	data->start_time = get_time();
	data->alive = 1;
	data->all_ate = 0;
	data->philos = malloc(sizeof(t_philo) * data->number_of_philo);
	if (!data->philos)
		return (1);
	if (pthread_mutex_init(&data->alive_lock, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->alive_lock);
		free(data->philos);
		return (1);
	}
	if (init_philosophers(data) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		pthread_mutex_destroy(&data->alive_lock);
		free(data->philos);
		return (1);
	}
	return (0);
}
