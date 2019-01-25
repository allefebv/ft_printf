/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:30:04 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/25 13:39:22 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_process_f(t_conv_spec conv_spec, va_list *ap)
{
	if (conv_spec.modifier[3] == 1)
		return (ft_itoa_double(conv_spec, va_arg(*ap, double)));
	if (conv_spec.modifier[4] == 1)
		return (ft_itoa_double(conv_spec, va_arg(*ap, long double)));
	return (ft_itoa_double(conv_spec, (float)va_arg(*ap, double)));
}
