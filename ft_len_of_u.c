/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_of_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlumbers <tlumbers@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 22:17:43 by tlumbers          #+#    #+#             */
/*   Updated: 2021/12/27 23:34:26 by tlumbers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunbr(unsigned long n)
{
	if (n < 10)
	{
		n = n + 48;
		write(1, &n, 1);
	}
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}

int	ft_len_of_u(unsigned long n)
{
	int	ind;

	ind = 0;
	ft_putunbr(n);
	if (n == 0)
		return (1);
	while (n)
	{
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
