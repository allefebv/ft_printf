/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 17:05:30 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/17 13:33:36 by jfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_conv_process(t_conv_spec conv_spec, va_list *ap)
{
	char	*str;

	str = ft_process_id(conv_spec, ap);
	str = ft_process_preci(conv_spec, str);
	str = ft_process_min_width(conv_spec, str);
	str = ft_process_flags(conv_spec, str);
	return (str);
}

int				ft_struct_create(t_conv_spec *conv_spec, char *format, int *i)
{
	int	len;

	len = ft_conv_id(conv_spec, format, *i);
	ft_flag(conv_spec, format, *i, len);
	ft_modifier(conv_spec, format, *i, len);
	ft_field_width(conv_spec, format, *i, len);
	ft_precision(conv_spec, format, *i, len);
	return (len);
}

char			*ft_conv_management(char *format, int *i, va_list *ap)
{
	t_conv_spec		conv_spec;
	int				len;
	char			*str;

	ft_struct_init(&conv_spec);
	len = ft_struct_create(&conv_spec, format, i);
	str = ft_conv_process(conv_spec, ap);
	*i = *i + len + 1;
	ft_struct_del(&conv_spec);
	return (str);
}

char			*ft_ordinary_management(char *format, int *i)
{
	int		j;
	char	*str;

	j = *i;
	while (format[j] != '%' && format[j] != '\0')
		j++;
	j = j - *i;
	str = ft_strndup((format + *i), j);
	*i = *i + j;
	return (str);
}

int				ft_printf(char *format, ...)
{
	va_list			ap;
	char			*result;
	int				i;
	int				ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	result = ft_strnew(0);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			result = ft_strextend(result, ft_ordinary_management(format, &i));
		else
			result = ft_strextend(result, ft_conv_management(format, &i, &ap));
	}
	ret = (int)ft_strlen(result);
	ft_char_replace(result, -1, 0);
	write(1, result, ret);
	free(result);
	va_end(ap);
	return (ret);
}
