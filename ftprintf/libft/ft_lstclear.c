/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:08:01 by taewanki          #+#    #+#             */
/*   Updated: 2022/11/21 18:21:13 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*temp;

	if (lst == 0 || *lst == 0 || del == 0)
		return ;
	now = *lst;
	while (now)
	{
		temp = now;
		now = now->next;
		ft_lstdelone(temp, del);
	}
	*lst = 0;
}
