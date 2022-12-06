/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:14:01 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/27 23:31:36 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(long n)
{
	if (n == -2147483648)
	{
		ft_putnbr(n / 10);
		write(1, "8", 1);
	}
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
		}
		if (n < 10)
		{
			n = n + 48;
			write(1, &n, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
}

int	ft_len_of_d(long n)
{
	int	ind;

	ind = 0;
	ft_putnbr(n);
	if (n == 0)
		return (1);
	while (n)
	{
		if (n < 0)
		{
			n = -n;
			ind++;
		}
		if (n > 9)
		{
			n = n / 10;
			ind++;
		}
		else
			return (++ind);
	}
	return (ind);
}
