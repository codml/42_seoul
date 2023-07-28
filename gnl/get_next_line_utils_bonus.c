/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:00:14 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/23 18:49:27 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	ptr->prev_fd = 0;
	ptr->next_fd = 0;
	return (ptr);
}

int	ft_find_fd(t_buflist **lst, int fd)
{
	t_buflist	*temp;

	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
		{
			*lst = temp;
			return (1);
		}
		temp = temp->next_fd;
	}
	temp = *lst;
	while (temp)
	{
		if (temp->fd == fd)
		{
			*lst = temp;
			return (1);
		}
		temp = temp->prev_fd;
	}
	return (0);
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
	if (!ft_find_fd(lst, node->fd))
	{
		ft_rebuild_lst(node, *lst, (*lst)->next_fd);
		*lst = node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	ft_rebuild_lst(t_buflist *node, t_buflist *p_node, t_buflist *n_node)
{
	if (!node)
	{
		if (p_node)
			p_node->next_fd = n_node;
		if (n_node)
			n_node->prev_fd = p_node;
	}
	else
	{
		if (p_node || n_node)
		{
			if (p_node)
			{
				node->prev_fd = p_node;
				p_node->next_fd = node;
			}
			if (n_node)
			{
				node->next_fd = n_node;
				n_node->prev_fd = node;
			}
		}
	}
}

void	ft_buflstclear_flag(t_buflist **node, int flag)
{
	t_buflist	*now;
	t_buflist	*temp;
	t_buflist	*next_node;
	t_buflist	*prev_node;

	if (node == 0 || *node == 0)
		return ;
	now = *node;
	prev_node = (*node)->prev_fd;
	next_node = (*node)->next_fd;
	while (now)
	{
		if (flag && !(now->next))
			break ;
		temp = now;
		now = now->next;
		free(temp->buf);
		free(temp);
	}
	*node = now;
	ft_rebuild_lst(*node, prev_node, next_node);
	if (*node == 0 && prev_node)
		*node = prev_node;
	else if (*node == 0 && next_node)
		*node = next_node;
}
