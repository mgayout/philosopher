/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:59 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 13:47:26 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (digit_args(argc, argv))
		return (1);
	if (ft_atoi(argv[1]) < 1)
		return (1);
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (1);
	return (0);
}

int	philo(int argc, char **argv)
{
	t_data	data;

	init_data(&data, argc, argv);
	if (init_malloc(&data))
		return (2);
	init_philo(&data);
	init_fork(&data);
	thread_routine(&data);
	join_threads(&data);
	free_data(&data);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(data);
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_data_nbphilo(data);
	i = -1;
	while (++i < nb_philos)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->get_value);
	pthread_mutex_destroy(&data->update_value);
	pthread_mutex_destroy(&data->writting);
	free(data->philo_ths);
	free(data->philo);
	free(data->fork);
}

int	main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	if (philo(argc, argv))
		return (2);
}
