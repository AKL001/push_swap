NAME= push_swap

SRCS = push_swap.c stack_init.c errors.c utils/stack_utils.c libft/ft_split.c libft/ft_substr.c \
		utils/push.c utils/rotate.c utils/re_rotate.c utils/swap.c \
		sort_list.c tools/sort_stack.c tools/sort_stack_tools.c 

DEPS = push_swap.h

OBJS = $(SRCS:.c=.o)


all : $(NAME)
	@make clean

$(NAME): $(OBJS)
	@ cc -Wall -Wextra -Werror $(OBJS) -o $(NAME) 
# -fsanitize=address

clean: 
	@rm -f $(OBJS) 

fclean:clean
	@rm -f $(NAME)

re: fclean all	
