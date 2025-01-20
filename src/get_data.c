/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:34:28 by mgayout           #+#    #+#             */
/*   Updated: 2025/01/20 12:20:07 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	get_data_nbphilo(t_data *data)
{
	int	data_nbphilo;

	pthread_mutex_lock(&data->get_value);
	data_nbphilo = data->nb_philo;
	pthread_mutex_unlock(&data->get_value);
	return (data_nbphilo);
}

int	get_data_timedie(t_data *data)
{
	int	data_timedie;

	pthread_mutex_lock(&data->get_value);
	data_timedie = data->time_to_die;
	pthread_mutex_unlock(&data->get_value);
	return (data_timedie);
}

int	get_data_timeeat(t_data *data)
{
	int	data_timeeat;

	pthread_mutex_lock(&data->get_value);
	data_timeeat = data->time_to_eat;
	pthread_mutex_unlock(&data->get_value);
	return (data_timeeat);
}

int	get_data_timesleep(t_data *data)
{
	int	data_timesleep;

	pthread_mutex_lock(&data->get_value);
	data_timesleep = data->time_to_sleep;
	pthread_mutex_unlock(&data->get_value);
	return (data_timesleep);
}

int	get_data_nbmeal(t_data *data)
{
	int	data_nbmeal;

	pthread_mutex_lock(&data->get_value);
	data_nbmeal = data->nb_meal;
	pthread_mutex_unlock(&data->get_value);
	return (data_nbmeal);
}
