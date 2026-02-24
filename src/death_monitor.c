/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 14:13:20 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/24 15:25:18 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_monitor(t_data *data)
{
	int i;
	t_philo *philos;

	while (data->alive == 1)
	{
		i = 0;
		while (&data->philos[i] < &data->number_of_philo - 1)
		{
			if (&data->alive != 1)
			{
				//opeste simularea
				print_state(&philos[i], "died\n");
				return (0);
			}
			if (&data->nb_meal == &philos->nb_meals)
			{
				//opeste simularea
				return (0);
			}
			i++;
		}
	}
	usleep(100);
}