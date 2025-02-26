SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
	ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_memset.c ft_bzero.c \
	ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_toupper.c \
	ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c 
# Object files generation (sources):
OBJS = $(SRCS:.c=.o)
BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	     ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	     ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
# Object files generation (bonus):
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
# Defining the directory:
INCS = ./
NAME = libft.a
LIBC = ar rcs

# Compiler:
CC = cc
RM = rm -f
# Flags:
CFLAGS = -Wall -Wextra -Werror

# Rule to compile the .o files from the .c files:
%.o: %.c 
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@  

# Rule to compile the main library:
$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	ranlib $(NAME)

# File compilation and library creation:
all: $(NAME)

# Rule to compile the bonus files:
bonus:  $(OBJS) $(BONUS_OBJS)
	$(LIBC) $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

so:
	$(CC) -nostartfiles -fPIC ${CFLAGS} ${SRCS}
	$(CC) -nostartfiles -shared -o libft.so ${OBJS} $(BONUS_OBJS)

clean:
		${RM} ${OBJS} $(BONUS_OBJS)

fclean: clean
		${RM} ${NAME}
		${RM} libft.so

re: fclean all

.PHONY: all clean fclean re bonus
