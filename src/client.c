/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:05:38 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 15:49:05 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	ft_send(int pid, char *str)
{
	int	byte;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		byte = 0;
		while (byte < 7)
		{
			if ((str[i] >> byte) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			byte++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > PID_MAX || pid < 100)
			ft_putstr_fd("check pid\n", 1);
		ft_send(pid, argv[2]);
	}
	else
		ft_putstr_fd("Error\n", 1);
	return (0);
}
