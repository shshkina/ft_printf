/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:52:20 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/18 02:30:44 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	buff_rev(char *buff, int len)
{
	int		i;
	char	tmp;

	i = (len / 2);
	while (i-- > 0)
	{
		tmp = buff[i];
		buff[i] = buff[len - i - 1];
		buff[len - i - 1] = tmp;
	}
}

void		pf_itoa_base(char *buff, unsigned long long n, int base)
{
	int		len;

	len = 0;
	while (n)
	{
		buff[len++] = "0123456789abcdef"[n % base];
		n /= base;
	}
	if (len == 0)
		buff[len++] = '0';
	buff[len] = '\0';
	buff_rev(buff, len);
}
