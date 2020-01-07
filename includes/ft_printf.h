/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:41:38 by iuolo             #+#    #+#             */
/*   Updated: 2019/12/28 19:31:59 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct		s_print
{
	const char 		*format;
	int				i;
	va_list			vl;
	int				res;
    char			type;
	char			*speth;
	char			*str;
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				point;
	unsigned int	p_i;
}					t_print;

int					ft_printf(const char *format, ...);

#endif
