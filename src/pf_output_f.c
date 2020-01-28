/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:09:16 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/28 23:00:01 by iuolo            ###   ########.fr       */
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
	unsigned long	un;
	unsigned long	pt;

	if (ptr->point == -1)
		ptr->point = 6;
	n = get_arg(ptr);
	if (n < 0)
		n = -n;
	un = (unsigned long)n;
	unsigned long		limit;
	
	limit = (unsigned long)((n - (long double)un) * pf_power(ptr->point));
	printf("%0.*u\n", ptr->point, limit);
	
	pf_itoa_base(ptr->buff, un, "0123456789");
	len = ft_strlen(ptr->buff);
	sign = '\0';
	if (ptr->space)
		sign = ' ';
	if (ptr->plus)
		sign = '+';
	if (n < 0)
		sign = '-';
	if (ptr->point == 0 && n == 0 && !sign)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	output_d(ptr, sign, len);
	output(ptr, sign, len);
}

// static inline double long			get_value(t_parse *self)
// {
// 	double long		result;

// 	if (self->fmt.length == LENGTH_CAP_L)
// 		result = (double long)va_arg(self->ap, double long);
// 	else
// 		result = (double long)va_arg(self->ap, double);
// 	return (result);
// }

// void								make(t_parse *self,
// 	unsigned long long part1, unsigned long long part2)
// {
// 	int		length;

// 	length = 0;
// 	while (part2)
// 	{
// 		self->temp[length++] = '0' + (part2 % 10);
// 		part2 = part2 / 10;
// 	}
// 	while (length < self->fmt.precision)
// 		self->temp[length++] = '0';
// 	if (length > 0)
// 		self->temp[length++] = '.';
// 	if (part1 == 0)
// 		self->temp[length++] = '0';
// 	while (part1)
// 	{
// 		self->temp[length++] = '0' + (part1 % 10);
// 		part1 = part1 / 10;
// 	}
// 	self->temp[length] = '\0';
// }

// static inline void					output(t_parse *self, char sign)
// {
// 	int		length;

// 	length = (int)ft_strlen(self->temp);
// 	if (sign)
// 		self->fmt.width -= 1;
// 	self->fmt.width -= length;
// 	if (!self->fmt.minus)
// 		output_repeat(self, ' ', self->fmt.width);
// 	if (sign)
// 		output_putchar(self, sign);
// 	while (length-- > 0)
// 		output_putchar(self, self->temp[length]);
// 	if (self->fmt.minus)
// 		output_repeat(self, ' ', self->fmt.width);
// }

// static inline unsigned long long	power10(int n)
// {
// 	unsigned long long	result;

// 	result = 1;
// 	while (n-- > 0)
// 		result *= 10;			
// 	return (result);
// }

// void								print_double(t_parse *self)
// {
// 	double long			value;
// 	char				sign;
// 	unsigned long long	part1;
// 	unsigned long long	pow10;

// 	value = get_value(self);
// 	sign = '\0';
// 	if (self->fmt.space)
// 		sign = ' ';
// 	if (self->fmt.plus)
// 		sign = '+';
// 	if (value < 0)
// 		sign = '-';
// 	if (value < 0)
// 		value = -value;
// 	if (self->fmt.precision < 0)
// 		self->fmt.precision = 6;
// 	pow10 = power10(self->fmt.precision + 1);
// 	part1 = (unsigned long long)value;
// 	value = (value - (double long)part1) * (double long)pow10;
// 	value = ((unsigned long long)value % 10 > 4) ? value / 10 + 1 : value / 10;
// 	part1 += (unsigned long long)value / (pow10 / 10);
// 	make(self, part1, (unsigned long long)value % (pow10 / 10));
// 	output(self, sign);
// }


// 10.0302

// 10

// '.'

// 10.0302 - 10 = 0.0302

// 0.0302 * 100000 = 03020

// 3020 = "3020" => "03020"











