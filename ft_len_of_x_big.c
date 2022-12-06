/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_x_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:55:40 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/27 23:40:57 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_hex_big(unsigned long n)
{
	if (n < 16)
	{
		if (n < 10)
		{
			n = n + 48;
			write(1, &n, 1);
		}
		else
		{
			n = n + 55;
			write(1, &n, 1);
		}
	}
	else
	{
		ft_putnbr_hex_big(n / 16);
		ft_putnbr_hex_big(n % 16);
	}
}

int	ft_len_of_x_big(unsigned long n)
{
	int	ind;

	ind = 0;
	ft_putnbr_hex_big(n);
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
