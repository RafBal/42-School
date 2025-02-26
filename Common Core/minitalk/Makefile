# Makefile generated with the help of ChatGPT.
# Compiler
CC = cc

C_FLAGS = -Wall -Werror -Wextra

# Directories:
FT_PRINTF_DIR = ./ft_printf
	# It refers to the root of the ft_printf project.
INCLUDES = -I$(FT_PRINTF_DIR)

# Static library produced by ft_printf:
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
	# It serves as a reference to the static library file produced by the ft_printf project.
# Source files
CLIENT_SRCS = client.c \
	      libft/ft_atoi.c \
	      libft/ft_isdigit.c

SERVER_SRCS = server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Executables
CLIENT = client
CLIENT2 = client2
SERVER = server

# Default targets
all: $(CLIENT) $(SERVER) #$(CLIENT2)

# Build client executable
$(CLIENT): $(CLIENT_OBJS) $(FT_PRINTF_LIB)
	$(CC) $(C_FLAGS) $(INCLUDES) -o $(CLIENT) $(CLIENT_OBJS) -L$(FT_PRINTF_DIR) -lftprintf

#$(CLIENT2): $(CLIENT_OBJS)
#	$(CC) $(C_FLAGS) -o $(CLIENT2) $(CLIENT_OBJS)

# Build server executable (target (executable): dependencies (.o and .a files))
$(SERVER): $(SERVER_OBJS) $(FT_PRINTF_LIB)
	$(CC) $(C_FLAGS) $(INCLUDES) -o $(SERVER) $(SERVER_OBJS) -L$(FT_PRINTF_DIR) -lftprintf
	# -L$(FT_PRINTF_DIR): Specifies where the linker should search for libraries.
	# -lftprintf: Tells the linker to use libftprintf.a (lib + ftprintf + .a).

# Building ft_printf before linking it (so libftprintf.a exists before attempting to use it):
$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

# Compile the object files in the present directory:
%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@
	# $< represents the current dependency (.c files)
	# $@ represents the target (.o files)

# Compile the object files from the ft_printf project
ft_printf/src/%.o: ft_printf/src/%.c
	$(CC) $(C_FLAGS) $(INCLUDES) -c $< -o $@

# Compile the object files from the libft project
libft/%.o: libft/%.c
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re
