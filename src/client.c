/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:09:50 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/14 16:20:48 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//	Acknowledge server resonse by printing the bit that was recieved by the server.

static void	acknowledge_sig(int sig)
{
	if (sig == SIGUSR1)
		printf("Server got 1\n");
	else if (sig == SIGUSR2)
		printf("Server got 0\n");
}


/*	Decode the currect character's bits and send SIGUSR1 when a 1 is read and SIGUSR2 when a 0 is read
	This function loops through the given entry string and then through the bits of each character. (1 - 8)
	usleep for 20 microseconds to make sure the signal is recieved before sending the next signal.
*/

static void	send_signal(int pid, char *str)
{
	int	i;
	int	b;
	int	bit;

	i = 0;
	while (str[i] != '\0')
	{
		b = 7;
		while (b >= 0)
		{
			bit = (str[i] >> b) & 1;
			if (bit == 1)
				kill(pid, SIGUSR1);
			else if (bit == 0)
				kill(pid, SIGUSR2);
			usleep(20);
			b --;
		}
		i ++;
	}
}


/*	Check for the correct number of arguments, has to be 3 (program name, server pid, string)
	Check of the pid contains any invalid characters (must be a positive integer)
	Install acknowledgement function for SIGUSR1 and SIGUSR2
	Send signal for the input string (argument 2)
	Send signal for a hard coded new line at the end of the input string
*/

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("\nInvalid number of arguments! (expected 2)\n");
		printf("		<PID> <string>\n \n");
		return (0);
	}
	if (!is_valid_id(av[1]))
	{
		printf("\n	Invalid PID!\n \n");
		return (0);
	}
	signal(SIGUSR1, acknowledge_sig);
	signal(SIGUSR2, acknowledge_sig);
	send_signal(ft_atoi(av[1]), av[2]);
	send_signal(ft_atoi(av[1]), "\n");
	return (0);
}
