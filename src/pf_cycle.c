/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:27:25 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/08 01:58:41 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flags(t_print *ptr)
{
	char	c;

	while ((c = ptr->format[ptr->i]))
	{
		if (c == '#')
			ptr->hash = 1;
		else if (c == '0')
			ptr->zero = 1;
		else if (c == '-')
			ptr->minus = 1;
		else if (c == '+')
			ptr->plus = 1;
		else if (c == ' ')
			ptr->space = 1;
		else
			break ;
		ptr->i++;
	}
}

void	pf_width(t_print *ptr)
{
	char	c;
	
	ptr->width = 0;
	while ((c = ptr->format[ptr->i]))
	{
		if (c >= '0' && c <= '9')
		{
			ptr->width = ptr->width * 10 + (c - '0');
			ptr->i++;
		}
		else 
			break ;
	}
}

void	pf_point(t_print *ptr)
{
	char	c;
	
	if (ptr->format[ptr->i] == '.')
	{
		ptr->i++;
		ptr->point = 0;
		while ((c = ptr->format[ptr->i]))
		{
			if (c >= '0' && c <= '9')
			{
				ptr->point = ptr->point * 10 + (c - '0');
				ptr->i++;
			}
			else 
				break ;
		}
	}
}

void	pf_length(t_print *ptr)
{
	char	c0;
	char	c1;
	
	ptr->length = LENGTH_NONE;
	c0 = ptr->format[ptr->i];
	if (c0)
	{
		c1 = ptr->format[ptr->i + 1];
		if (c0 == 'h' && c1 == 'h')
		{
			ptr->length = LENGTH_HH;
			ptr->i += 2;			
		}
		else if (c0 == 'h')
		{
			ptr->length = LENGTH_H;
			ptr->i += 1;
		}
		else if (c0 == 'l' && c1 == 'l')
		{
			ptr->length = LENGTH_LL;
			ptr->i += 2;			
		}
		else if (c0 == 'l')
		{
			ptr->length = LENGTH_L;
			ptr->i += 1;
		}
		else if (c0 == 'L')
		{
			ptr->length = LENGTH_BIG_L;
			ptr->i += 1;
		}
	}
}

void	pf_type(t_print *ptr)
{
	ptr->type = ptr->format[ptr->i];
	ptr->i++;
}

void	pf_cycle(t_print *ptr)
{
	char	c;

	while ((c = ptr->format[ptr->i]))
	{
		if (c == '%')
		{
			ptr->i++;
			pf_flags(ptr);
			pf_width(ptr);
			pf_point(ptr);
			pf_length(ptr);
			pf_type(ptr);
		}
		else
		{
			ft_putchar(c);
			ptr->i++;
		}
	}
}