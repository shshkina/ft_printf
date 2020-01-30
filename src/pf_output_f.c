/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:09:16 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/30 22:13:54 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	get_arg(t_print *ptr)
{
	long double		n;

	if (ptr->length == LENGTH_BIG_L)
		n = (long double)va_arg(ptr->vl, long double);
	else
		n = (long double)va_arg(ptr->vl, double);
	return (n);
}

static void			output_d(t_print *ptr, char sign, int len)
{
	if (sign)
		ptr->width -= 1;
	if (ptr->minus)
		ptr->zero = 0;
	if (ptr->point <= 0 && ptr->zero)
		ptr->point = ptr->width;
	ptr->point -= len;
	ptr->width -= len;
	if (ptr->point > 0)
		ptr->width -= ptr->point;
}

static void			output(t_print *ptr, char sign, int len)
{
	if (ptr->minus)
	{
		if (sign)
			pf_putchar(ptr, sign);
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width);
		if (sign)
			pf_putchar(ptr, sign);
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

static unsigned long	pf_power(int n)
{
	unsigned long	res;
	
	res = 1;
	while (n > 0)
	{
		res *= 10;
		n--; 
	}
	return (res);
}

void				pf_output_f(t_print *ptr)
{
	int				len;
	char			sign;
	long double		n;
	long double		nnnn;
	unsigned long	un;
	unsigned long	pt;
	int				len2;

	if (ptr->point == -1)
		ptr->point = 6;
	
	if (ptr->point > 0)
		ptr->width -= ptr->point;
	
	n = get_arg(ptr);
	nnnn = n;
	sign = '\0';
	if (ptr->space)
		sign = ' ';
	if (ptr->plus)
		sign = '+';
	if (n < 0)
		sign = '-';
	if (n < 0)
		n = -n;
	//unsigned long		limit;
	//pt = pt(ptr->point + 1);
	
	pt = pf_power(ptr->point + 1);
	un = (unsigned long long)n;
	n = (n - (double long)un) * (double long)pt;
	n = ((unsigned long long)n % 10 > 4) ? n / 10 + 1 : n / 10;
	un += (unsigned long long)n / (pt / 10);
	
	printf("%d\n", ptr->point);

	// limit = (unsigned long)n;
	// printf("%0.*u\n", ptr->point, limit);
	
	pf_itoa_base(ptr->buff, un, "0123456789");
	pf_itoa_base(ptr->buff2, (unsigned long)n, "0123456789");
	len = ft_strlen(ptr->buff);
	len2 = ft_strlen(ptr->buff2);
	if (ptr->point > 0)
		ptr->buff[len++] = '.';
	if (ptr->point == 0 && n == 0 && !sign)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	if (ptr->point == 0)
	{
		ptr->buff2[0] = '\0';
		len2 = 0;
	}
	if (ptr->minus)
		pf_repeat(ptr, ' ', ptr->width - 1);
	else
		pf_repeat(ptr, ' ', ptr->width);
	if (sign)
		pf_putchar(ptr, sign);
	pf_putnstr(ptr, ptr->buff, len);
	pf_repeat(ptr, '0', ptr->point - len2);
	pf_putnstr(ptr, ptr->buff2, len2);
}
