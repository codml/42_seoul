/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:48:28 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/18 17:23:23 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	ch;

	ch = '0' + n % 10;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		write(fd, &ch, 1);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		write(fd, &ch, 1);
	}
}
