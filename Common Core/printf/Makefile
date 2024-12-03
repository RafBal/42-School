# Compiler:
CC = cc

CFLAGS = -Wall -Wextra -Werror

# Directories:
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = .

# Files:
NAME = libftprintf.a
SRCS = $(SRC_DIR)/ft_printf.c \
       $(SRC_DIR)/ft_printf_conversions.c \
       $(SRC_DIR)/ft_putnbr_fd_count.c \
       $(SRC_DIR)/ft_put_uns_nbr_count.c \
       $(SRC_DIR)/ft_nbrn_count.c 

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# % = any
# List of objects that comes from the conversion from .c to .o files. It goes from the source directory to the object directory.

# Rules:

all: $(NAME)
# all is the default rule that is run when make command is used to create the specified library in NAME.

$(NAME): $(OBJS)
# rule on how to create the NAME (=libftprintf.a)
	ar rcs $@ $^
	# ar = a tool to create static libraries
	# rcs: flags for ar
		# r: replace existing files or add new ones.
		# c: create the library if it doesn't exist.
		# s: archive indexing to speed up linking.
	# $@: The target name ($(NAME)).
	# $^: All the prerequesites ($(OBJS)).
# Combines all object files into the static library.

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	# Pattern rule for compiling source files into object files.
	mkdir -p $(OBJ_DIR)
	# Making sure that the object directory exists before compiling.
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@
	# -I $(INC_DIR): include the directory containing header files.
	# -c $<: compile the source file, a.k.a first dependency ($<).
	# -o $@: output the compiled file to the object file ($@).
# This rule compiles each .c file in the source directory into a corresponding .o file in the object directory.

clean:
	rm -rf $(OBJ_DIR)
	# It removes directories and files recursively.
fclean: clean
	rm -f $(NAME)
	# After running clean, it removes the final executable file named $(NAME).
re: fclean all
	# It will run fclean first, then all.

.PHONY: all clean fclean re
	# Specifying that these are commands, and not files.
