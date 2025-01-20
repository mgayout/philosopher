/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:43:11 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/20 12:20:32 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	philo_died(t_philo *philo)
{
	bool		result;
	t_data		*data;

	data = philo->data;
	result = false;
	if (gettime() - get_philo_lasteat(philo) > get_data_timedie(data))
		result = true;
	return (result);
}

void	stop_philo(t_data *data)
{
	int		i;
	int		nb_philo;

	nb_philo = get_data_nbphilo(data);
	i = -1;
	while (++i < nb_philo)
		update_iter(data, false);
}
