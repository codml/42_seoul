/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:45 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/16 16:05:52 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buflist
{
	int					fd;
	char				*buf;
	struct s_buflist	*next;
}				t_buflist;
int			ft_findnewline(t_buflist *node, int *flag);
size_t		ft_fillstr(t_buflist *node, char **str);
int			ft_update_buffer(t_buflist **node, size_t idx, size_t lst_len);
char		*ft_returnline(t_buflist **node);
char		*get_next_line(int fd);
t_buflist	*ft_buflstnew(int fd);
void		ft_buflstadd_back(t_buflist **lst, t_buflist *node);
void		ft_buflstclear(t_buflist **lst);
void		ft_buflstclear_n(t_buflist **node, size_t n);

#endif
