/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:09:16 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/28 20:45:40 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"

// static long double	get_arg(t_print *ptr)
// {
// 	long double		n;

// 	if (ptr->length == LENGTH_BIG_L)
// 		n = (long double)va_arg(ptr->vl, long double);
// 	else
// 		n = (long double)va_arg(ptr->vl, double);
// 	return (n);
// }


// static void			output_d(t_print *ptr, char sign, int len)
// {
// 	if (sign)
// 		ptr->width -= 1;
// 	if (ptr->minus)
// 		ptr->zero = 0;
// 	if (ptr->point <= 0 && ptr->zero)
// 		ptr->point = ptr->width;
// 	ptr->point -= len;
// 	ptr->width -= len;
// 	if (ptr->point > 0)
// 		ptr->width -= ptr->point;
// }

// static void			output(t_print *ptr, char sign, int len)
// {
// 	if (ptr->minus)
// 	{
// 		if (sign)
// 			pf_putchar(ptr, sign);
// 		pf_repeat(ptr, '0', ptr->point);
// 		pf_putnstr(ptr, ptr->buff, len);
// 		pf_repeat(ptr, ' ', ptr->width);
// 	}
// 	else
// 	{
// 		pf_repeat(ptr, ' ', ptr->width);
// 		if (sign)
// 			pf_putchar(ptr, sign);
// 		pf_repeat(ptr, '0', ptr->point);
// 		pf_putnstr(ptr, ptr->buff, len);
// 	}
// }



// void				pf_output_f(t_print *ptr)
// {
// 	int				len;
// 	char			sign;
// 	long double		n;
// 	unsigned long	un;
// 	unsigned long	pt;

// 	n = get_arg(ptr);
// 	if (n < 0)
// 		n = -n;
// 	un = (unsigned long)n;
	
	pf_itoa_base(ptr->buff, un, "0123456789");
// 	len = ft_strlen(ptr->buff);
// 	sign = '\0';
// 	if (ptr->space)
// 		sign = ' ';
// 	if (ptr->plus)
// 		sign = '+';
// 	if (n < 0)
// 		sign = '-';
// 	if (ptr->point == 0 && n == 0 && !sign)
// 	{
// 		ptr->buff[0] = '\0';
// 		len = 0;
// 	}
// 	output_d(ptr, sign, len);
// 	output(ptr, sign, len);
// }
