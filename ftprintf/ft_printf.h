/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:43:39 by taewanki          #+#    #+#             */
/*   Updated: 2023/01/03 19:57:50 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_conv(va_list ap, char ch, int *num);
int		ft_conv2(va_list ap, char ch, int *num);
int		ft_putnbr_base(long long nb, char *base, long long len);
int		ft_cntlen(long long nb, long long len);
int		ft_print_p(va_list ap, int *num);
int		ft_print_d(va_list ap, int *num);
int		ft_print_i(va_list ap, int *num);
int		ft_print_u(va_list ap, int *num);
int		ft_print_x(va_list ap, int *num, char ch);

#endif
