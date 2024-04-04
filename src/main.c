/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgayout <mgayout@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:52:59 by mgayout           #+#    #+#             */
/*   Updated: 2024/04/04 13:41:59 by mgayout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (digit_args(argc, argv))
		return (1);
	if (ft_atoi(argv[1]) < 1)
		return (1);
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) < 0)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	if (philo(argc, argv))
		return (2);
	printf("ok\n");
}