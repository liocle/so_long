/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lclerc <lclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:01:48 by lclerc            #+#    #+#             */
/*   Updated: 2023/05/15 15:38:32 by lclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * atol() converts the initial portion of the string pointed to by 'str' to
 * 'int' dsf representation
 */

#include "libft.h"

int	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || ((*str >= 9) && (*str <= 13)))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
