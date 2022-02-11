/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:11:13 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/24 11:06:51 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_connect(pid_t s_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		usleep(200);
		kill(s_pid, SIGUSR2);
		i++;
	}
	exit(0);
}

void	ft_send_bit(char *s, pid_t pid)
{
	static int				i = 8;
	static unsigned char	c;
	static char				*str;
	static pid_t			s_pid;

	if (s)
	{
		str = s;
		s_pid = pid;
		c = *str;
	}
	if (!i)
	{
		i = 8;
		c = *(++str);
		if (!c)
			ft_connect(s_pid);
	}
	if (c && c >> --i & 0x01)
		kill(s_pid, SIGUSR1);
	else if (c)
		kill(s_pid, SIGUSR2);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *unused)
{
	static int	r_byt = 1;

	(void)siginfo;
	(void)unused;
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\rreceive bytes: ", 1);
		ft_putnbr_fd(r_byt, 1);
		r_byt++;
	}
	ft_send_bit(0, 0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3 || !(100 <= ft_atoi(argv[1]) && ft_atoi(argv[1]) <= 99998))
	{
		ft_putstr_fd("check pid and argument\n", 1);
		return (1);
	}
	if (!ft_strlen(argv[2]))
		exit(0);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_putstr_fd("send bytes   : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("receive bytes: ", 1);
	ft_send_bit(argv[2], ft_atoi(argv[1]));
	while (1)
		pause();
	return (0);
}
