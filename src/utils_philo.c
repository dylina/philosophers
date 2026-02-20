/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:22:02 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/20 14:03:32 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	get_alive(t_data *data)
{
	int	val;

	pthread_mutex_lock(&data->alive_lock);
	val = data->alive;
	pthread_mutex_unlock(&data->alive_lock);
	return (val);
}

void	precise_sleep(long ms, t_data *data)
{
	long	start_time;
	long	elapsed_time;

	start_time = get_time();
	while (1)
	{
		elapsed_time = get_time() - start_time;
		if (elapsed_time >= ms)
			break ;
		if (!get_alive(data))
			break ;
		usleep(100);
	}
}

void	print_state(t_philo *philo, char *msg)
{
	long int	timestamp;

	pthread_mutex_lock(&philo->data->print_lock);
	if (get_alive(philo->data))
	{
		timestamp = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}
