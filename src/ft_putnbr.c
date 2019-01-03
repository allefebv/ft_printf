/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <jfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:47:14 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/03 12:24:04 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, '-', 1);
		write(1, '2', 1);
		n = 147483648;
	}
	if (n < 0)
	{
		write(1, '-', 1);
		n = -n;
	}
	if (n < 10)
		write(1, n + 48, 1);
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}