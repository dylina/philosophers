/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:14:15 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/20 15:39:52 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int i;
	t_philo *philos;

	i = 0;
	while (i < data->number_of_philo)
	{
		philos = &data->philos[i];
		if (pthread_create(&philos->philo_thread, NULL, routine, philos) != 0)
		{
			printf("Error: pthread_create failed!\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_threads(t_data *data)
{
	int i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(data->philos[i].philo_thread, NULL);
		i++;
	}
	return (0);
}
