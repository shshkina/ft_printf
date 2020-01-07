/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:27:25 by iuolo             #+#    #+#             */
/*   Updated: 2019/12/28 19:51:19 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_cycle(t_print *ptr)
{
	char	c;

	while ((c = ptr->format[ptr->i]))
	{
		if (c == '%')
		{
			ptr->i++;
			pf_flags(ptr);

		}
		else
		{
			ft_putchar(c);
			ptr->i++;
		}
	}
}

void	pf_flags(t_print *ptr)
{
	if (ptr->format[ptr->i] == '#')
	{
		ptr->hash = 1;
		ptr->i++;
	}
	
	if (ptr->format[ptr->i] == '0')
	{
		ptr->zero = 1;
		ptr->i++;
	}
	 
}
