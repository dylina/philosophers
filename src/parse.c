/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:37:15 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/26 17:03:23 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error : nbr of args\n");
		return (1);
	}
	if (!is_digit(argc, argv))
	{
		printf("Error : is not valid\n");
		return (1);
	}
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->nb_meal = -1;
	if (argc == 6)
		data->nb_meal = ft_atoi(argv[5]);
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0 || data->number_of_philo <= 0
		|| (argc == 6 && data->nb_meal <= 0))
	{
		printf("Error : change your args!\n");
		return (1);
	}
	return (0);
}
