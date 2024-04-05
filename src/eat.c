/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:11:02 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 18:15:57 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	eat_routine(t_philo *philo)
{
	if (philo_died(philo) || !get_data_iter(philo->data))
		return (1);
	if (take_forks(philo) != 0)
		return (1);
	if (philo_died(philo) || !get_data_iter(philo->data))
		return (1);
	printf("iter %d\n", get_data_iter(philo->data));
	philo_writting(philo, "is eating");
	update_lasteat(philo);
	ft_usleep(get_data_timeeat(philo->data));
	update_nbmeal(philo);
	drop_forks(philo);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (get_data_nbphilo(philo->data) == 1)
	{
		if (philo_died(philo) || !get_data_iter(philo->data))
			return (1);
		pthread_mutex_lock(philo->left_fork);
		philo_writting(philo, "has taken a fork");
		ft_usleep(get_data_timedie(philo->data));
		return (1);
	}
	if (philo_died(philo) || !get_data_iter(philo->data))
		return (1);
	pthread_mutex_lock(philo->left_fork);
	philo_writting(philo, "has taken a fork");
	if (philo_died(philo) || !get_data_iter(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	pthread_mutex_lock(philo->right_fork);
	philo_writting(philo, "has taken a fork");
	return (0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
