/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:11:22 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/23 15:19:18 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static unsigned char	c = 0x00;
	static int				byt = 0;
	static pid_t			c_pid = 0;

	(void)unused;
	if (!c_pid)
		c_pid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++byt == 8)
	{
		byt = 0;
		if (c == 0x00)
		{
			c_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0x00;
		kill(c_pid, SIGUSR1);
	}
	else
	{
		c <<= 1;
		kill(c_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("message : ", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
