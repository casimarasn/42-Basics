NAME = pipex
INCLUDE = pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft/inc
RM = rm -rf

OBJDIR = obj

#librarys
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = pipex.c\
		errors_free.c\
		process.c\
		setup.c\


OBJS = $(addprefix $(OBJDIR)/, $(FILES:%.c=%.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@echo "🛠 Compiling $<..."
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) 
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Compilation finished successfully."

#build libft only if libft.a is outdated
$(LIBFT):
	@echo "📦 Building libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "🧹 Cleaning objects & dependencies..."
	@$(RM) $(OBJDIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑 removing executables & libreries..."
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "✅ Cleanup completed successfully."
re: fclean all

# Include automatically generated dependencies
-include $(DEPS) 

.PHONY: all clean fclean re