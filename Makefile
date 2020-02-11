# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffood <ffood@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:03:43 by htrent            #+#    #+#              #
#    Updated: 2020/02/11 15:26:30 by htrent           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: $(NAME) all compile fclean clean re

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra -c

HEADERS_LIST = ft_printf.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./srcs/
SOURCES_LIST = ft_atoi.c \
	   ft_isdigit.c \
	   ft_itoa.c \
	   ft_istrchr.c \
	   ft_putchar.c \
	   ft_putchar_buf.c \
	   ft_putstr_buf.c \
	   ft_putstr.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_strnew.c \
	   ft_toupper.c \
	   ft_atoi_base.c \
	   ft_bzero.c \
	   ft_printf.c \
	   ft_pow.c \
	   ft_count_of_digits.c \
	   ft_utoa_base.c \
	   ft_str_to_upper.c \
	   put_x.c \
	   put_exception.c \
	   put_di.c \
	   ft_memset.c \
	   width_prec_size.c \
	   flags.c \
	   utils.c \
	   put_p.c \
	   put_u.c \
	   put_o.c \
	   put_c.c \
	   put_c_zero.c \
	   put_s.c \
	   put_f.c \
	   help_utils_di.c \
	   help_utils_x.c \
	   help_utils_s.c \
	   help_utils_o.c \
	   power_five.c \
	   put_b.c \
	   help_utils_b.c \
	   put_r.c \
	   color.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
BOLD_GREEN = \033[1;32m
RED = \033[0;31m
BOLD_RED = \033[1;31m
YELLOW = \033[0;33m
BOLD_YELLOW = \033[1;33m
BLUE = \033[0;34m
BOLD_BLUE = \033[1;34m
MAGENTA = \033[0;35m
BOLD_MAGENTA = \033[1;35m
CYAN = \033[0;36m
BOLD_CYAN = \033[1;36m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
		@ar rc $(NAME) $(OBJECTS)
		@ranlib $(NAME)
		@echo "\n$(BOLD_YELLOW)$(NAME)$(RESET):$(BOLD_BLUE) ready to use!$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@gcc $(FLAGS) -I $(HEADERS_DIRECTORY) $< -o $@
	@echo "$(GREEN).$(RESET)\c"



clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(BOLD_YELLOW)$(NAME)$(RESET): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f libftprintf.a
	@echo "$(BOLD_RED)$(NAME) deleted$(RESET)"


re:
	@$(MAKE) fclean
	@$(MAKE) all
