/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:19:59 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/23 22:34:17 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = BUFFERSIZE - 1;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int i;
	pid_t server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <messages>", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (i < (int)ft_strlen(argv[2]))
	{
		send_char(server_pid, argv[2][i]);
		i++;
	}
	return (0);
}