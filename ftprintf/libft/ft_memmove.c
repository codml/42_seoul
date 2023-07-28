/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:00:51 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/27 19:23:34 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	p_dst = dst;
	p_src = src;
	while (i < len)
	{
		if ((p_src < p_dst) && (p_src + len > p_dst))
			p_dst[len - i - 1] = p_src[len - i - 1];
		else
			p_dst[i] = p_src[i];
		i++;
	}
	return (dst);
}
