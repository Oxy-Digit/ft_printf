/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 23:05:38 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/27 23:32:25 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_of_x_p(unsigned long n)
{
	int	ind;

	ind = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		if (n > 15)
		{
			n = n / 16;
			ind++;
		}
		else
			return (++ind);
	}
	return (ind);
}

int	ft_treat_ptr(unsigned long n)
{
	if (n == 0)
		return (write(1, "0x0", 3));
	else
	{
		write(1, "0x", 2);
		ft_putnbr_hex(n);
	}
	return ((ft_len_of_x_p(n) + 2));
}
