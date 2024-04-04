/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:06:08 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/04 16:32:31 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long long	gettime(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = gettime();
	while ((gettime() - start) < time)
		usleep(500);
}

void	philo_writting(t_philo *philo, char *str)
{
	pthread_mutex_lock(&(philo->data->writting));
	printf("%lli %d ", (gettime() - philo->data->start_time), philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(&(philo->data->writting));
}

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

bool	nb_meals_option(t_data *data)
{
	if (data->nb_meal > 0)
		return (true);
	return (false);
}
