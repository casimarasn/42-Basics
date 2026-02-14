# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msedeno- <msedeno-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 11:54:30 by msedeno-          #+#    #+#              #
#    Updated: 2026/02/14 14:45:02 by msedeno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

# Directories
INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj

# Correct include path 
INCLUDES    = -I$(INC_DIR)

# Conversions
SRC_CONV = conversions/ft_atoi.c conversions/ft_atoi_strict.c \
		conversions/ft_itoa.c conversions/atod.c

# Ctype
SRC_CTYPE = ctype/ft_isalnum.c ctype/ft_isalpha.c ctype/ft_isascii.c \
			ctype/ft_isdigit.c ctype/ft_isprint.c ctype/ft_isspace.c \
			ctype/ft_tolower.c ctype/ft_toupper.c

# GNL
SRC_GNL = gnl/get_next_line.c

# Lists
SRC_LISTS = lists/ft_lstadd_back.c lists/ft_lstadd_front.c lists/ft_lstclear.c \
			lists/ft_lstdelone.c lists/ft_lstiter.c lists/ft_lstlast.c \
			lists/ft_lstmap.c lists/ft_lstnew.c lists/ft_lstsize.c

# Math
SRC_MATH = math/ft_abs.c math/sort_int_array.c

# Memory
SRC_MEM = mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c \
			mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c \
			mem/ft_memset.c

# Printf
SRC_PRINTF = printf/ft_printf.c printf/ft_print_char.c printf/ft_print_format.c \
			printf/ft_print_hexdecma.c printf/ft_print_hexdecmi.c \
			printf/ft_print_nbr.c printf/ft_print_percent.c \
			printf/ft_print_pointer.c printf/ft_print_string.c \
			printf/ft_print_unsigned.c

# Put
SRC_PUT = put/ft_putchar_fd.c put/ft_putendl_fd.c \
			put/ft_putnbr_fd.c put/ft_putstr_fd.c

# String
SRC_STR = string/ft_split.c string/ft_strchr.c string/ft_strdup.c \
			string/ft_striteri.c string/ft_strjoin.c string/ft_strjoin_space.c \
			string/ft_strlcat.c string/ft_strlcpy.c string/ft_strlen.c \
			string/ft_strmapi.c string/ft_strncmp.c string/ft_strnstr.c \
			string/ft_strrchr.c string/ft_strtrim.c string/ft_substr.c

# Concatenate all sources
SRCS = $(addprefix $(SRC_DIR)/, \
		$(SRC_CONV) $(SRC_CTYPE) $(SRC_GNL) $(SRC_LISTS) \
		$(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF) $(SRC_PUT) $(SRC_STR))

# Object generation (Mirror directory structure)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# --- Rules ---

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

# Compilation rule that creates the obj directory if it doesn't exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@echo "Objects cleaned."

fclean: clean
	$(RM) $(NAME)
	@echo "Library removed."

re: fclean all

.PHONY: all clean fclean re