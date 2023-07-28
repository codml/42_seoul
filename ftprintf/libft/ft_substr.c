/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:06:23 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/07 17:45:43 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_checksize(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len <= start || !len)
		return (0);
	else
	{
		if (s_len - start > len)
			return (len);
		else
			return (s_len - start);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	size = ft_checksize(s, start, len);
	if (!size)
		ptr = (char *)malloc(sizeof(char));
	else
		ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (0);
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
