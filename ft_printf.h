/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:20:44 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/28 00:16:04 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_len_of_u(unsigned long n);
int		ft_len_of_d(long n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *fst, ...);
int		ft_len_of_x(unsigned long n);
int		ft_len_of_x_big(unsigned long n);
int		ft_treat_ptr(unsigned long n);
void	ft_putnbr_hex(unsigned long n);

#endif
