/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:33:26 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/29 17:39:27 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (haystack[i] == *needle)
		{
			if (len - i < ft_strlen(needle))
				return (0);
			if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (0);
}
