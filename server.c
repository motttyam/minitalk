/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:19:53 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/28 00:54:01 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

pid_t	g_client_pid = 0;

void	print_bit(int *bits, int count)
{
	int		i;
	char	byte;

	i = 0;
	byte = 0;
	while (i < count)
		byte = (byte << 1) | bits[i++];
	if (byte != '\0')
		ft_printf("%c", byte);
	else
	{
		kill(g_client_pid, SIGUSR1);
		g_client_pid = 0;
	}
}

void	receive_bit(int sig, siginfo_t *info, void *context)
{
	static int	bits[BUFFERSIZE];
	static int	count;

	if (g_client_pid == 0)
		g_client_pid = info->si_pid;
	if (sig == SIGUSR1)
		bits[count++] = 0;
	else
		bits[count++] = 1;
	if (count == BUFFERSIZE)
	{
		print_bit(bits, count);
		if (context == NULL)
			ft_bzero(bits, sizeof(bits));
		count = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_bit;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
