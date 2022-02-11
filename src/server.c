/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:20:03 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 15:13:48 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	ft_get_signal(int bit)
{
	static t_struct	sig;

	sig.c += ((bit & 1) << sig.count);
	sig.count++;
	if (sig.count == 7)
	{
		write (1, &sig.c, 1);
		if (!sig.count)
			ft_putstr_fd("\n", 1);
		sig.count = 0;
		sig.c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("message : ", 1);
	while (1)
	{
		signal(SIGUSR2, ft_get_signal);
		signal(SIGUSR1, ft_get_signal);
		pause();
	}
	return (0);
}
