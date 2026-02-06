NAME = libftprintf.a
INCLUDE = ft_printf.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

OBJ_DIR = obj

FILES = ft_printf.c \
		ft_print_format.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_percent.c \
		ft_print_nbr.c \
		ft_print_unsigned.c \
		ft_print_hexdecma.c \
		ft_print_hexdecmi.c \
		ft_print_pointer.c


OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re