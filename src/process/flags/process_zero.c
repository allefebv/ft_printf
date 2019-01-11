/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:16:02 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/11 15:07:29 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_zero(t_conv_spec conv_spec, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
