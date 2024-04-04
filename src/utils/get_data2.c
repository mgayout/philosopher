/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:34:22 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/04 16:32:14 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

bool	get_data_iter(t_data *data)
{
	bool	data_iter;

	pthread_mutex_lock(&data->get_value);
	data_iter = data->iterating;
	pthread_mutex_unlock(&data->get_value);
	return (data_iter);
}

