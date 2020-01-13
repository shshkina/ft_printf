/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:56:40 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/13 19:00:11 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putchar(t_print *ptr, char c)
{
	write(1, &c, 1);
	ptr->res++;
}