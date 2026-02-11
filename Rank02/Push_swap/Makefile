NAME = push_swap
BONUS_NAME = checker
INCLUDE = push_swap.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
RM = rm -rf

OBJDIR = obj
OBJDIR_BONUS = obj_bonus

#librarys
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = arguments.c \
		arguments_utils.c \
		costs_utils.c \
		find_nodes.c \
		free.c \
		is_valid.c \
		moves_multi.c \
		moves_ps.c \
		moves_r.c \
		presort_to_b.c \
		push_swap.c \
		sort_sizes.c \
		stack_build.c \
		stacks_utils.c \
		target_b_to_a.c

FILES_BONUS = arguments_bonus.c \
			arguments_utils_bonus.c \
			free_bonus.c \
			is_valid_bonus.c \
			moves_multi_bonus.c \
			moves_ps_bonus.c \
			moves_r_bonus.c \
			push_swap_bonus.c \
			stacks_utils_bonus.c \
			stack_build_bonus.c

OBJS = $(addprefix $(OBJDIR)/, $(FILES:%.c=%.o))
OBJS_BONUS = $(addprefix $(OBJDIR_BONUS)/, $(notdir $(FILES_BONUS:%.c=%.o)))
all: $(NAME)


$(OBJDIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJDIR)
	@echo "🛠 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR_BONUS)/%.o: bonus/%.c $(INCLUDE)
	@mkdir -p $(OBJDIR_BONUS)
	@echo "🛠 Compiling Bonus $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "✅ Compilation finished successfully."

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	@echo "🔗 Linking $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)
	@echo "✅ Compilation Bonus completed."

#build libft only if libft.a is outdated
$(LIBFT):
	@echo "📦 Building libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "🧹 Cleaning objects..."
	@$(RM) $(OBJDIR) $(OBJDIR_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑 removing executables & libreries..."
	@$(RM) $(NAME) $(BONUS_NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "✅ Cleanup completed successfully."
re: fclean all

.PHONY: all bonus clean fclean re