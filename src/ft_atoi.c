/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraf <jgraf@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:53:57 by jgraf             #+#    #+#             */
/*   Updated: 2024/11/14 13:58:08 by jgraf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


/*	Check if all characters in the string are numbers.
	Negative numbers are set as invalid because a minus sign is not a number
*/

int	is_valid_id(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i ++;
	}
	return (1);
}


//	Convert the string in to a valid interger, by adding the character value

int	ft_atoi(const char	*str)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val *= 10;
		val += str[i ++] - '0';
	}
	return (val);
}
