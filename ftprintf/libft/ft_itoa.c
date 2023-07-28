/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:35:18 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/26 20:12:06 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_len(long long nb)
{
	int		cnt;

	cnt = 0;
	if (nb >= 0 && nb <= 9)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		cnt++;
	}
	return (cnt);
}

static char	*ft_itoa_minus(long long nb)
{
	int		idx;
	char	*ptr;

	nb *= -1;
	idx = ft_cnt_len(nb);
	ptr = (char *)malloc(sizeof(char) * (idx + 2));
	if (!ptr)
		return (0);
	ptr[0] = '-';
	ptr[idx + 1] = '\0';
	while (idx > 0)
	{
		ptr[idx--] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}

static char	*ft_itoa_plus(int nb)
{
	int		idx;
	char	*ptr;

	idx = ft_cnt_len(nb);
	ptr = (char *)malloc(sizeof(char) * (idx + 1));
	if (!ptr)
		return (0);
	ptr[idx] = '\0';
	while (--idx >= 0)
	{
		ptr[idx] = nb % 10 + '0';
		nb /= 10;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	if (n < 0)
		return (ft_itoa_minus(n));
	else
		return (ft_itoa_plus(n));
}
