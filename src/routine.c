/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:39:56 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 18:16:29 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thread_routine(t_data *data)
{
	int	i;
	int	nb_of_philos;

	nb_of_philos = get_data_nbphilo(data);
	i = -1;
	data->start_time = gettime();
	while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&philo_routine, &data->philo[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&dead_routine, data))
		return (1);
	return (0);
}

void	*philo_routine(void *void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	update_lasteat(philo);
	if (philo->id % 2 == 0)
		usleep(5000);
	while (get_data_iter(philo->data) && !philo_died(philo))
	{
		//update_iter(philo->data, false);
		printf("iter %d\n", get_data_iter(philo->data));
		if (eat_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->data))
			break ;
		if (sleep_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->data))
			break ;
		if (think_routine(philo) != 0)
			break ;
		if (philo_died(philo) || !get_data_iter(philo->data))
			break ;
	}
	return (NULL);
}

void	*dead_routine(void *void_data)
{
	int		i;
	int		nb_philo;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *)void_data;
	philo = data->philo;
	nb_philo = get_data_nbphilo(data);
	i = -1;
	while (++i < nb_philo && get_data_iter(data))
	{
		//printf("philo id : %d\n", philo[i].id);
		if (philo_died(&philo[i]) && get_data_iter(data))
		{
			stop_philo(data);
			philo_writting(&philo[i], "died");
			break ;
		}
		if (i == nb_philo - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}
