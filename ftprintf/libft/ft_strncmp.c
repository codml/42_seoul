/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:27:06 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/16 21:49:36 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;

	i = 0;
	p_s1 = (const unsigned char *)s1;
	p_s2 = (const unsigned char *)s2;
	while (p_s1[i] && p_s2[i] && i < n)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	if (i < n)
		return (p_s1[i] - p_s2[i]);
	return (0);
}
