/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:35:14 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 18:07:15 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_philo_lasteat(t_philo *philo)
{
	long long	lasteat;

	pthread_mutex_lock(&philo->data->get_value);
	lasteat = philo->lasteat;
	pthread_mutex_unlock(&philo->data->get_value);
	return (lasteat);
}
