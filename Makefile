NAME= push_swap
BONUS = checker

SRCS = push_swap.c stack_init.c errors.c utils/stack_utils.c libft/ft_split.c libft/ft_substr.c \
		utils/push.c utils/rotate.c utils/re_rotate.c utils/swap.c \
		sort_list.c tools/sort_stack.c tools/sort_stack_tools.c \
		tools/tiny_sorts.c

BNS_SRCS = checker.c stack_init.c libft/ft_strncmp.c libft/ft_split.c errors.c libft/ft_substr.c  \
			checker_utils/checker_push.c checker_utils/checker_re_rotate.c \
			checker_utils/checker_rotate.c checker_utils/checker_swap.c utils/stack_utils.c \
			checker_utils/checker_errors.c

DEPS = push_swap.h

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

all : $(NAME)

bonus :$(BONUS)

$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

$(BONUS) : $(BNS_OBJS)
	cc -Wall -Wextra -Werror $(BNS_OBJS) -o $(BONUS)

%.o:%.c
	cc -Wall -Wextra -Werror  -c $< -o $@
	
clean: 
	@rm -f $(OBJS) $(BNS_OBJS)

fclean:clean
	@rm -f $(NAME) $(BONUS)

re: fclean all	
