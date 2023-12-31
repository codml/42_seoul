/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:07:28 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/13 17:49:33 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c < 0 || c > 255)
		return (0);
	else if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
