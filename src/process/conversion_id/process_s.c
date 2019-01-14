/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfleury <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:04:24 by jfleury           #+#    #+#             */
/*   Updated: 2019/01/14 17:28:24 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_process_s(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_strdup(va_arg(*ap, char*));
	str = ft_precision_s(conv_spec, str);
	str = ft_process_min_width(conv_spec, str);
	str = ft_process_flags(conv_spec, str);
	
	return (str);
}
