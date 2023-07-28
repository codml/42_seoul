/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:12 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/16 16:51:02 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_findnewline(t_buflist *node, int *flag)
{
	size_t		i;

	if (!node)
		return (0);
	if ((node->buf)[0] == 0)
	{
		*flag = 1;
		return (1);
	}
	while (node->next)
		node = node->next;
	if ((node->buf)[0] == 0)
		return (1);
	i = 0;
	while ((node->buf)[i])
	{
		if ((node->buf)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_fillstr(t_buflist *node, char **str)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (node)
	{
		j = 0;
		while ((node->buf)[j])
		{
			(*str)[i] = (node->buf)[j];
			if ((node->buf)[j] == '\n')
			{
				i++;
				j++;
				break ;
			}
			i++;
			j++;
		}
		node = node->next;
	}
	(*str)[i] = 0;
	return (j);
}

int	ft_update_buffer(t_buflist **node, size_t idx, size_t lst_len)
{
	char		*temp;
	char		*new;
	size_t		i;
	size_t		j;

	ft_buflstclear_n(node, lst_len - 1);
	temp = (*node)->buf;
	i = 0;
	while (temp[i])
		i++;
	if (i == idx)
	{
		ft_buflstclear(node);
		return (1);
	}
	new = (char *)malloc(i - idx + 1);
	if (!new)
		return (0);
	j = 0;
	while (j++ < i - idx)
		new[j - 1] = temp[idx + j - 1];
	new[j - 1] = 0;
	(*node)->buf = new;
	free(temp);
	return (1);
}

char	*ft_returnline(t_buflist **node)
{
	size_t		lst_len;
	size_t		idx;
	t_buflist	*ptr;
	char		*str;

	ptr = *node;
	lst_len = 0;
	while (ptr)
	{
		ptr = ptr->next;
		lst_len++;
	}
	str = (char *)malloc(lst_len * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	idx = ft_fillstr(*node, &str);
	if (!ft_update_buffer(node, idx, lst_len))
		ft_buflstclear(node);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buflist	*head;
	t_buflist			*temp;
	int					flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	flag = 0;
	while (!ft_findnewline(head, &flag))
	{
		temp = ft_buflstnew(fd);
		if (!temp)
		{
			ft_buflstclear(&head);
			return (0);
		}
		ft_buflstadd_back(&head, temp);
	}
	if (flag)
	{
		ft_buflstclear(&head);
		return (0);
	}
	return (ft_returnline(&head));
}
