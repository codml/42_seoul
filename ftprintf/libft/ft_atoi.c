/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:51 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/28 16:34:46 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_out(long *p_ret, char ch, int *minus)
{
	if (*minus == 1)
	{
		if (*p_ret > LONG_MAX / 10 || (*p_ret == LONG_MAX / 10
				&& ch - '0' >= LONG_MAX % 10))
		{
			*p_ret = LONG_MAX;
			*minus = 1;
			return (1);
		}
	}
	else
	{
		if (*p_ret > LONG_MAX / 10 || (*p_ret == LONG_MAX / 10
				&& (ch - '1') >= LONG_MAX % 10))
		{
			*p_ret = LONG_MIN;
			*minus = 1;
			return (1);
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		minus;
	long	ret;

	minus = 1;
	ret = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		if (ft_out(&ret, *str, &minus))
			break ;
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return ((int)(ret * minus));
}
