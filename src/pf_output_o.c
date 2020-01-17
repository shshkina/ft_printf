/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:46:39 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/18 02:53:41 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_output_o(t_print *ptr)
{
	unsigned long long	n;
    int                 len;

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