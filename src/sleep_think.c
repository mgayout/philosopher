/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:09:41 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/20 12:20:26 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	sleep_routine(t_philo *philo)
{
	if (philo_died(philo) || !get_data_iter(philo->data))
		return (1);
	philo_writting(philo, "is sleeping");
	ft_usleep(get_data_timesleep(philo->data));
	return (0);
}

int	think_routine(t_philo *philo)
{
	if (philo_died(philo)  || !get_data_iter(philo->data))
		return (1);
	philo_writting(philo, "is thinking");
	return (0);
}
