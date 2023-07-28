/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:59:21 by taewanki          #+#    #+#             */
/*   Updated: 2022/12/21 21:47:49 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
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
	struct s_buflist	*prev_fd;
	struct s_buflist	*next_fd;
}				t_buflist;
int			ft_findnewline(t_buflist **node, int *flag, int fd);
size_t		ft_fillstr(t_buflist *node, char **str);
void		ft_update_buffer(t_buflist **node, size_t idx);
char		*ft_returnline(t_buflist **node);
char		*get_next_line(int fd);
t_buflist	*ft_buflstnew(int fd);
int			ft_find_fd(t_buflist **lst, int fd);
void		ft_buflstadd_back(t_buflist **lst, t_buflist *node);
void		ft_rebuild_lst(t_buflist *node,
				t_buflist *p_node, t_buflist *n_node);
void		ft_buflstclear_flag(t_buflist **node, int flag);

#endif
