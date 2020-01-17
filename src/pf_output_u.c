/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:46:39 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/18 02:51:29 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_output_u(t_print *ptr)
{
	unsigned long long	n;
    int                 len;

    if (ptr->length == LENGTH_HH)
	    n = (unsigned long long)(unsigned char)va_arg(ptr->vl, unsigned int);
    else if (ptr->length == LENGTH_H)
        n = (unsigned long long)(unsigned short)va_arg(ptr->vl, unsigned int);
    else if (ptr->length == LENGTH_L)
        n = (unsigned long long)va_arg(ptr->vl, unsigned long);
    else if (ptr->length == LENGTH_LL)
        n = (unsigned long long)va_arg(ptr->vl, unsigned long long);
    else
        n = (unsigned long long)va_arg(ptr->vl, unsigned);
    pf_itoa_base(ptr->buff, n, 10);
    len = ft_strlen(ptr->buff);
    if (ptr->point <= 0 && ptr->zero)
        ptr->point = ptr->width;
    ptr->point -= len;
    ptr->width -= len;
    if (ptr->point > 0)
        ptr->width -= ptr->point;
	if (ptr->minus)
	{
		pf_repeat(ptr, '0', ptr->point);
        pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
        pf_repeat(ptr, ' ', ptr->width);
        pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}