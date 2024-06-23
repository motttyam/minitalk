/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:19:53 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 22:39:13 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	receive_bit(int sig)
{
	static int	bits[BUFFERSIZE];
	static int	count;
	char		byte;
	int			i;

	if (sig == SIGUSR1)
	{
		bits[count++] = 0;
	}
	else
	{
		bits[count++] = 1;
	}
	if (count == BUFFERSIZE)
	{
		byte = 0;
		i = 0;
		while (i < count)
			byte = (byte << 1) | bits[i++];
		ft_printf("%c", byte);
		ft_bzero(bits, BUFFERSIZE);
		count = 0;
	}
}

int	main(void)
{
	pid_t pid;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, receive_bit);
	signal(SIGUSR2, receive_bit);
	while (1)
		pause();
	return (0);
}