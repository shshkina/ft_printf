/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:59:34 by iuolo             #+#    #+#             */
/*   Updated: 2019/12/28 18:30:23 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

void ft_putchar (char c)
{
	write(1, &c, 1);
}

void fun(char *s, ...)
{
	va_list	vl;
	int 	i;

	i = -1;
	va_start(vl, s);
	while (s[++i])
	{
		if(s[i] != '%')
		{
			ft_putchar(s[i]);
		}
		else
		{
			++i;
			if (s[i] == 'd' || s[i] == 'i')
				ft_putnbr(va_arg(vl, signed int));
			else if (s[i] == 'u') 
			
				ft_putnbr(va_arg(vl, unsigned int));
			else if (s[i] == 's')
				ft_putstr(va_arg(vl, char*));
		}
	}
	va_end(vl);
}

int main()
{
	fun("123 %u %i %s\n", -25, -25, "q");
	return (0);
}
