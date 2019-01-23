/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrnchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:33:56 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/23 13:27:50 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrnchr(const char *s, int c, int n)
{

	while (s[n] != c)
		n--;
	if (s[n] == c)
		return ((char*)s + n);
	else
		return (NULL);
}
