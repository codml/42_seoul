/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:47:53 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/27 16:27:57 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	s;

	s = count * size;
	if (count != 0)
	{
		if (size != s / count)
			return (0);
	}
	ptr = (void *)malloc(s);
	if (!ptr)
		return (0);
	ft_bzero(ptr, s);
	return (ptr);
}
