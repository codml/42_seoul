/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:51:56 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/30 14:31:44 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntstrs(char const *str, char c)
{
	size_t	i;
	size_t	cnt;

	if (!str[0])
		return (0);
	i = 0;
	cnt = 0;
	while (str[i])
	{
		if ((str[i] != c) && (str[i + 1] == c))
			cnt++;
		i++;
	}
	if (c != 0 && str[i - 1] != c)
		cnt++;
	return (cnt);
}

static size_t	ft_strlen_c(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static int	ft_putstrs(char const *str, char c, size_t cnt, char **pptr)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		while (*str && (*str == c))
			str++;
		ptr = (char *)malloc(ft_strlen_c(str, c) + 1);
		if (!ptr)
			return (0);
		pptr[i] = ptr;
		while (*str && (*str != c))
		{
			*ptr = *str;
			ptr++;
			str++;
		}
		*ptr = 0;
		while (*str && (*str != c))
			str++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	size_t	cnt;
	char	**pptr;

	if (!str)
		return (0);
	cnt = ft_cntstrs(str, c);
	pptr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!pptr)
		return (0);
	ft_bzero(pptr, sizeof(char *) * (cnt + 1));
	if (ft_putstrs(str, c, cnt, pptr))
		return (pptr);
	else
	{
		i = 0;
		while (pptr[i])
			free(pptr[i++]);
		free(pptr);
		return (0);
	}
}
