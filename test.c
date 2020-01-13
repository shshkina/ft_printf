/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:52:33 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/13 22:57:22 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	char *str = "Hello!!";
	
	ft_printf("|%10s|\n", str);
	printf("|%10s|\n", str);
	
	ft_printf("|%-10s|\n", str);
	printf("|%-10s|\n", str);

	
	ft_printf("|%10.4s|\n", str);
	printf("|%10.4s|\n", str);

	return (0);
}
