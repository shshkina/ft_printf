/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:52:33 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/18 02:46:47 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int		main(void)
{
	// char *str = "Hello!!";
	
	// ft_printf("|%10s|\n", str);
	// printf("|%10s|\n", str);
	
	// ft_printf("|%-10s|\n", str);
	// printf("|%-10s|\n", str);

	
	// ft_printf("|%10.4s|\n", str);
	// printf("|%10.4s|\n", str);
	
	// int n;
	// char	buff[100];
	

	// n = 25485;
	// if (n > 0)
	// 	pf_itoa_base(buff, n, 16, 0);
	// else
	// 	pf_itoa_base(buff, -n, 16, 1);
	
	// ft_putstr(buff);
	//    printf("|@moulitest: |%5.d| |%5.0d|\n", 0, 0);
	// ft_printf("|@moulitest: |%5.d| |%5.0d|\n", 0, 0);

	//    printf("|%hd|\n", -32768);
	// ft_printf("|%hd|\n", -32768);
	   printf("%015u\n", 4294967295);
	ft_printf("%015u\n", 4294967295);
	// ft_printf("|%5.4d|\n", -34);
	// printf("|%5.4d|\n", -34);
	return (0);
}
