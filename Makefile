NAME= push_swap
BONUS = checker

SRCS = push_swap.c stack_init.c errors.c utils/stack_utils.c libft/ft_split.c libft/ft_substr.c \
		utils/push.c utils/rotate.c utils/re_rotate.c utils/swap.c \
		sort_list.c tools/sort_stack.c tools/sort_stack_tools.c \
		tools/tiny_sorts.c

BNS_SRCS = checker.c stack_init.c libft/ft_strncmp.c libft/ft_split.c errors.c libft/ft_substr.c  \
			utils/stack_utils.c  utils/rotate.c utils/swap.c \
			utils/push.c utils/re_rotate.c 

DEPS = push_swap.h

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

all : $(NAME)
	@make clean

bonus :$(BONUS)
	@make clean

$(NAME): $(OBJS)
	@ cc -Wall -Wextra -Werror $(OBJS) -o $(NAME) -fsanitize=address 
# -fsanitize=address
$(BONUS) : $(BNS_OBJS)
	@ cc -Wall -Wextra -Werror $(BNS_OBJS) -o $(BONUS) -fsanitize=address 
	
clean: 
	@rm -f $(OBJS) $(BNS_OBJS)

fclean:clean
	@rm -f $(NAME) $(BONUS)

re: fclean all	
