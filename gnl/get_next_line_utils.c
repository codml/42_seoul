/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:22 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/16 18:16:21 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buflist	*ft_buflstnew(int fd)
{
	t_buflist	*ptr;
	ssize_t		num;

	ptr = (t_buflist *)malloc(sizeof(t_buflist));
	if (!ptr)
		return (0);
	ptr->buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!(ptr->buf))
	{
		free(ptr);
		return (0);
	}
	num = read(fd, ptr->buf, BUFFER_SIZE);
	if (num == -1)
	{
		free(ptr->buf);
		free(ptr);
		return (0);
	}
	(ptr->buf)[num] = 0;
	ptr->fd = fd;
	ptr->next = 0;
	return (ptr);
}

void	ft_buflstadd_back(t_buflist **lst, t_buflist *node)
{
	t_buflist	*temp;

	if (lst == 0 || node == 0)
		return ;
	else if (*lst == 0)
	{
		*lst = node;
		return ;
	}
	else if ((*lst)->fd != node->fd)
	{
		ft_buflstclear(lst);
		*lst = node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	ft_buflstclear(t_buflist **lst)
{
	t_buflist	*now;
	t_buflist	*temp;

	if (lst == 0 || *lst == 0)
		return ;
	now = *lst;
	while (now)
	{
		temp = now;
		now = now->next;
		free(temp->buf);
		free(temp);
	}
	*lst = 0;
}

void	ft_buflstclear_n(t_buflist **node, size_t n)
{
	size_t		i;
	t_buflist	*ptr;
	t_buflist	*temp;

	ptr = *node;
	i = 0;
	while (i < n)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp->buf);
		free(temp);
		i++;
	}
	*node = ptr;
}
