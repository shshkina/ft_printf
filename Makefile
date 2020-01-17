# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 18:55:55 by iuolo             #+#    #+#              #
#    Updated: 2020/01/17 23:35:02 by iuolo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

INC_DIR     = ./includes
SRC_DIR     = ./src
OBJ_DIR     = ./obj

HEADERS     = ft_printf.h
SOURCES     = ft_printf.c \
			  pf_cycle.c \
			  pf_repeat.c \
			  pf_output_esc.c \
			  pf_output_chr.c \
			  pf_output_str.c \
			  pf_output_u.c \
			  pf_output_d.c \
			  pf_putchar.c \
			  pf_putnstr.c \
			  pf_itoa_base.c

LIBFT       = ./libft
CC          = gcc
WFLAGS      = #-Wall -Wextra -Werror
IFLAGS      = -I$(INC_DIR) -I$(LIBFT)

INCS        = $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS        = $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS        = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)/
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT)/ clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT)/ fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)
	rm -rf test

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

test: test.c $(NAME)
	$(CC) $(IFLAGS) $^ -L. -lftprintf -o $@

.PHONY: all clean fclean re
