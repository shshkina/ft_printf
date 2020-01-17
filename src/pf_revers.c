/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 21:57:48 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/17 21:59:10 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_revers(t_print *ptr, char *str)
{
	int		len;
	
	len = ft_strlen(str);
	while (len-- > 0)
		pf_putchar(ptr, str[len]);
}