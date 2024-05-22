# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afont <afont@student.42nice.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 09:25:13 by afont             #+#    #+#              #
#    Updated: 2024/05/22 10:10:24 by afont            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	$(shell find ./sources -name '*.c')
OBJ_DIR = obj_o
OBJS	= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf
NAME	=	libft.a
TOTAL_FILES = $(words $(SRCS))

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@count=$$(find $(OBJ_DIR) -name '*.o' | wc -l); \
	i=1; \
	while [ $$i -le $$count ]; do \
		echo -n "▰"; \
		i=$$((i + 1)); \
	done; \
	while [ $$i -le $(TOTAL_FILES) ]; do \
		echo -n "═"; \
		i=$$((i + 1)); \
	done; \
	echo -n "  $$((($$count * 100) / $(TOTAL_FILES)))% Compiling $$(basename $<)...\r"

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean :
	@$(RM) $(OBJS) $(NAME)
	@rm -rf obj_o

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.SILENT:
.PHONY : all, libft.a, clean, fclean, re