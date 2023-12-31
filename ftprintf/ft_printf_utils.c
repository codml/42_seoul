/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:06:33 by taewanki          #+#    #+#             */
/*   Updated: 2023/01/03 20:00:05 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	ft_cntlen(unsigned long long nb, unsigned long long len)
{
	int		cnt;

	cnt = 0;
	if (nb >= 0 && nb <= len - 1)
		return (1);
	while (nb > 0)
	{
		nb /= len;
		cnt++;
	}
	return (cnt);
}

int	ft_putnbr_base(unsigned long long nb, char *base, unsigned long long len)
{
	int		i;
	int		idx;
	char	*ptr;

	idx = ft_cntlen(nb, len);
	ptr = (char *)malloc(idx);
	if (!ptr)
		return (0);
	i = idx - 1;
	while (i >= 0)
	{
		ptr[i] = base[nb % len];
		nb /= len;
		i--;
	}
	if (write(1, ptr, idx) != idx)
	{
		free(ptr);
		return (0);
	}
	free(ptr);
	return (1);
}
