/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:34:15 by rceschel          #+#    #+#             */
/*   Updated: 2025/01/07 11:34:16 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	count_digits(unsigned int n)
{
	int	d;

	d = 1;
	n /= 10;
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

int	ft_printunbr(unsigned int n)
{
	ft_putunbr(n);
	return (count_digits(n));
}
