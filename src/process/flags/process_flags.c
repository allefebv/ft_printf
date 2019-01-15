/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allefebv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:02:32 by allefebv          #+#    #+#             */
/*   Updated: 2019/01/15 13:24:10 by allefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	ft_init_table(t_fptr_flag *table)
{
	int		max;
	int		i;

	i = 0;
	max = 4;
	while (i < max)
	{
		table[i].flags = 1;
		i++;
	}
	table[0].fptr = &ft_process_hash;
	table[1].fptr = &ft_process_zero;
	//table->fptr[2] = &ft_process_minus;
	table[3].fptr = &ft_process_plus;
	return (max);
}*/

static int	ft_init_table(t_fptr_flag *table)
{
	int		max;
	int		i;

	max = 4;
	i = 0;
	table->flags = ft_memalloc(sizeof(int) * max);
	while (i < max)
	{
		table->flags[i] = 1;
		i++;
	}
	table->fptr[0] = &ft_process_space;
	table->fptr[1] = &ft_process_zero;
	table->fptr[2] = &ft_process_minus;
	table->fptr[3] = &ft_process_plus;
	return (max);
}

char		*ft_process_flags(t_conv_spec conv_spec, char *str)
{
	t_fptr_flag		*table;
	int				i;
	int				max;

	i = 0;
	table = ft_memalloc(sizeof(*table) * FLAGS_NB);
	max = ft_init_table(table);
	while (i < max)
	{
		if (conv_spec.flags[i] == table->flags[i])
			str = table->fptr[i](conv_spec, str);
		i++;
	}
	free(table->flags);
	free(table);
	return (str);
}
