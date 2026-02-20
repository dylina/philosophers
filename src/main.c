/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorceac <dgorceac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:12:50 by dgorceac          #+#    #+#             */
/*   Updated: 2026/02/20 15:44:17 by dgorceac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data data;
	if (argc < 5 || argc > 7)
	{
		printf("Error : args error\n");
		return 1;
    }
	if (parse_args(&data, argc, argv))
		return 1;
	if (init_data(&data))
		return 1;
	
	create_threads(&data);
    //death_monitor
    join_threads(&data);
    // free threads mutex destroy si malocurile pt data si philo
	
	return 0;
}
