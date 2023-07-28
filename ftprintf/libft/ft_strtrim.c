/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:12:26 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/29 18:11:01 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_findidx(char const *s1, char const *set, size_t *idx)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;

	if (s1[0] == 0)
		return (0);
	len_s1 = ft_strlen(s1);
	i = 0;
	j = len_s1 - 1;
	while (i < len_s1)
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	*idx = i;
	if (i == len_s1)
		return (0);
	while (j > i)
	{
		if (!ft_strchr(set, s1[j]))
			break ;
		j--;
	}
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	idx;
	size_t	len;

	if (!s1 || !set)
		return (0);
	len = ft_findidx(s1, set, &idx);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[idx];
		i++;
		idx++;
	}
	ptr[i] = '\0';
	return (ptr);
}
