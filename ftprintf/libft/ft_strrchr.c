/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:00:54 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/28 17:21:03 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;

	ret = 0;
	while (*s)
	{
		if (*s == (char)c)
			ret = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)ret);
}
