SRCS = $(shell find ./sources -name '*.c')
HEADER = $(shell find ./includes -name '*.h')
OBJ_DIR = Objects
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3d
LIB = libft/libft.a
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11
OPTI_FLAGS = -Ofast -flto -march=native -funroll-loops -fexpensive-optimizations -finline-functions -fomit-frame-pointer
MATH_FLAGS = -lm
TOTAL_FILES = $(words $(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@tput civis
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -g -c $< -o $@
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

$(NAME): $(OBJS) includes/cub3d.h
	@make -C libft --no-print-directory
	@printf "\033[2K\r"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) $(MATH_FLAGS) -o $(NAME)
	@echo -n "   \033[37;42;1m$(NAME) created\033[0m\n"
	@tput cnorm

run: $(NAME)
	./$(NAME) Maps/map1.cub

clean:
	@make clean -C libft --no-print-directory
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "   \033[41;1mObject file deleted\033[0m"

fclean: clean
	@make fclean -C libft --no-print-directory
	@rm -rf $(NAME)
	@echo "   \033[41;1m$(NAME) deleted\033[0m"

re: fclean all

.SILENT:
.PHONY: all clean fclean re run 
