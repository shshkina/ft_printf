/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:49:32 by iuolo             #+#    #+#             */
/*   Updated: 2019/12/28 19:32:44 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void foo(char *fmt, ...) {
//         va_list ap;
//         int d;
//         char c, *p, *s;
//         va_start(ap, fmt);
//         while (*fmt)
//                 switch(*fmt++) {
//                 case 's':                       /* строка */
//                         s = va_arg(ap, char *);
//                         printf("строка %s\n", s);
//                         break;
//                 case 'd':                       /* целое */
//                         d = va_arg(ap, int);
//                         printf("целое %d\n", d);
//                         break;
//                 case 'c':                       /* символ */
//                         /* необходимо указание типов, т.к. va_arg
//                         воспринимает только полностью определенные типы */
//                         c = (char) va_arg(ap, int);
//                         printf("символ %c\n", c);
//                         break;
//                 }
//         va_end(ap);
// }

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_print		ptr;
	char		c;

	ft_bzero(&ptr, sizeof(ptr));
	ptr.format = format;	
	va_start(ptr.vl, format);
	pf_cycle(&ptr);	
	va_end(ptr.vl);
	return (ptr.res);
}
