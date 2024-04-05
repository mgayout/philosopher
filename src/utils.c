/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:06:08 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/05 14:10:24 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
