/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:12:50 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/26 15:50:19 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc < 5 || argc > 6)
	{
		printf("Error : args error\n");
		return 1;
    }
	if (parse_args(&data, argc, argv))
		return 1;
	if (init_data(&data))
		return 1;
	create_threads(&data);
	death_monitor(&data);
	join_threads(&data);
	cleanup(&data);
	return 0;
}
