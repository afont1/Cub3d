SRCS = $(shell find ./sources -name '*.c')
HEADER = $(shell find ./includes -name '*.h')
OBJ_DIR = Objects
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
LIB = libft/libft.a
MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11
OPTI_FLAGS = -Ofast -flto -march=native -funroll-loops -fexpensive-optimizations -finline-functions -fomit-frame-pointer
MATH_FLAGS = -lm
TOTAL_FILES = $(words $(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@tput civis
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(OPTI_FLAGS) -c $< -o $@
	count=$$(find $(OBJ_DIR) -name '*.o' | wc -l); \
	str="████████████████████"; \
	len_str=$$((($$count * 20) / $(TOTAL_FILES) * 3)); \
	len_space=$$((20 - $$len_str / 3)); \
	printf "\033[36m%.*s%*c\033[0m%% %d\r" $$len_str $$str $$len_space ' ' $$((($$count * 100) / $(TOTAL_FILES))); \

$(NAME): $(OBJS) includes/cub3d.h
	@make -C libft --no-print-directory
	@printf "\033[2K\r"
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) $(MATH_FLAGS) -o $(NAME)
	@echo -n "   \033[37;46;1m$(NAME) created\033[0m\n"
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
