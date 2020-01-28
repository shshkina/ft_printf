/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:52:33 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/28 20:53:49 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char *str;

	str = "Hello!!";
	// ft_printf("|%10s|\n", str);
	// printf("|%10s|\n", str);
	// ft_printf("|%-10s|\n", str);
	// printf("|%-10s|\n", str);
	// ft_printf("|%10.4s|\n", str);
	// printf("|%10.4s|\n", str);
	// printf("|@moulitest: |%5.d| |%5.0d|\n", 0, 0);
	// ft_printf("|@moulitest: |%5.d| |%5.0d|\n", 0, 0);
	// printf("|%#x|\n", 0);
	// ft_printf("|%#x|\n", 0);
	// ft_printf("|%5.4d|\n", -34);
	// printf("|%5.4d|\n", -34);
	// printf("|%4.s|\n", "42");
	// ft_printf("|%4.s|\n", "42");

//    printf("|@moulitest: %o|\n", 0);
// ft_printf("|@moulitest: %o|\n", 0);
//    printf("|@moulitest: %.o %.0o|\n", 0, 0);
// ft_printf("|@moulitest: %.o %.0o|\n", 0, 0);
//    printf("|%#o|\n", 0);
// ft_printf("|%#o|\n", 0);


	//    printf("{%#.5x}\n", 1);
 	// ft_printf("{%#.5x}\n", 1);

	// ft_printf_fd(1, "11111\n");
	// ft_printf_fd(2, "22222\n");

	// ft_printf("|%d|\n", 42);
	// ft_printf("|%b|\n", 42);
	// ft_printf("|%#b|\n", -1);

	// ft_printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}\n", "filename", "str");
	
	ft_printf("|{0}|\n");
	ft_printf("|{%s}|\n", 0);
	printf("|{%s}|\n", 0);
	
 	return (0);
}
