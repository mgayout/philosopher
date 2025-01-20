/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:44:25 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/20 12:20:29 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	update_lasteat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->update_value);
	philo->lasteat = gettime();
	pthread_mutex_unlock(&philo->data->update_value);
}

void	update_nbmeal(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->update_value);
	philo->meal += 1;
	pthread_mutex_unlock(&philo->data->update_value);
}

void	update_iter(t_data *data, bool update)
{
	pthread_mutex_lock(&data->update_value);
	data->iterating = update;
	pthread_mutex_unlock(&data->update_value);
}
