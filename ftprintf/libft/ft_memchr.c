/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:17:26 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/26 16:08:14 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p_s;

	i = 0;
	p_s = s;
	while (i < n)
	{
		if (p_s[i] == (unsigned char)c)
			return ((void *)(p_s + i));
		i++;
	}
	return (0);
}
