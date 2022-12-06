/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:23:26 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/27 23:46:13 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_spec(const char *fst, va_list ap, int nbr)
{
	if (*fst == 'd' || *fst == 'i')
		nbr = ft_len_of_d(va_arg(ap, int));
	else if (*fst == 'u')
		nbr = ft_len_of_u(va_arg(ap, unsigned int));
	else if (*fst == 'c')
		nbr = ft_putchar(va_arg(ap, int));
	else if (*fst == '%')
		nbr = ft_putchar('%');
	else if (*fst == 's')
		nbr = ft_putstr(va_arg(ap, char *));
	else if (*fst == 'x')
		nbr = ft_len_of_x(va_arg(ap, unsigned int));
	else if (*fst == 'X')
		nbr = ft_len_of_x_big(va_arg(ap, unsigned int));
	else if (*fst == 'p')
		nbr = ft_treat_ptr(va_arg(ap, unsigned long));
	return (nbr);
}

static int	find_formspec(const char *fst, va_list ap, int nbr)
{
	while (*fst)
	{
		if (*fst == '%')
		{
			fst++;
			nbr += print_spec(fst, ap, nbr);
		}
		else
		{
			write(1, fst, 1);
			nbr++;
		}
		fst++;
	}
	return (nbr);
}

int	ft_printf(const char *fst, ...)
{
	va_list	ap;
	int		nbr;

	nbr = 0;
	va_start(ap, fst);
	nbr = find_formspec(fst, ap, nbr);
	va_end(ap);
	return (nbr);
}
