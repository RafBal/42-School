# Compiler and Flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Directories
SRC_DIR = src
BONUS_SRC_DIR = src_bonus
LIBFT_DIR = libft
MLX_DIR = minilibx-linux
INCLUDE_DIR = include
BONUS_INCLUDE_DIR = include_bonus

# Source and Object Files (Mandatory)
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/events.c \
       $(SRC_DIR)/rendering.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/double_only.c \
       $(SRC_DIR)/initializing.c

OBJS = $(SRCS:.c=.o)

# Source and Object Files (Bonus)
BONUS_SRCS = $(BONUS_SRC_DIR)/main_bonus.c \
             $(BONUS_SRC_DIR)/events_bonus.c \
             $(BONUS_SRC_DIR)/rendering_bonus.c \
             $(BONUS_SRC_DIR)/utils_bonus.c \
             $(BONUS_SRC_DIR)/double_only_bonus.c \
             $(BONUS_SRC_DIR)/initializing_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx_Linux.a

# Compiler Flags for MiniLibX
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -lX11 -lXext -lm

# Executable Names
NAME = fractol
BONUS_NAME = fractol_bonus

# Compilation Rules
all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

# Object File Compilation (Mandatory)
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -Ilibft -c $< -o $@

# Object File Compilation (Bonus)
$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(BONUS_INCLUDE_DIR) -Ilibft -c $< -o $@

# Clean Rules
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

