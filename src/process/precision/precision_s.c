/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:06:14 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 18:01:50 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision_s(t_conv_spec conv_spec, char *str)
{
	char	*str2;

	if (conv_spec.precision == -1)
		return (str);
	str2 = ft_strnew(conv_spec.precision);
	ft_strncat(str2, str, conv_spec.precision);
	free(str);
	return (str2);
}
