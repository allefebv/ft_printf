/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:04:31 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/18 19:32:58 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if (!(s1) || !(s2))
		return (0);
	if (!(ft_strcmp(s1, s2)))
		return (1);
	return (0);
}
