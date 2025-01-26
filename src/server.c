/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:18:02 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/14 13:59:44 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


/*	Create an "empty" char, set to 0 and with every recieved signal from the client
	count the recieved signal (SIGUSR1 = 1; SIGUSR2 = 0) to the char.
	When there are 8 bits recieved, a char is complete, print the created char and reset
	the char as well as the counter for the next char.
*/

static void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	i = 0;
	pid_t		client_pid;

	(void)ucontext;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << (7 - i));
	else if (sig == SIGUSR2)
		c &= ~(1 << (7 - i));
	if (sig == SIGUSR1 || sig == SIGUSR2)
		kill(client_pid, sig);
	i ++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}


/*	Print the servers pid.
	Install the signal handler for the server, create the sigaction struct to be able
	to get the clients pid.
	Enter infinite loop to await incoming signals for the client.
*/

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	printf("\n   Server's PID: %i\n \n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
