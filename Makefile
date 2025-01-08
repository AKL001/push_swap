NAME= push_swap

SRCS = push_swap.c stack_init.c errors.c utils/stack_utils.c libft/ft_split.c libft/ft_substr.c

DEPS = push_swap.h

OBJS = $(SRCS:.c=.o)


all : $(NAME)
	@make clean

$(NAME): $(OBJS)
	@ cc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

clean: 
	@rm -f $(OBJS) 

fclean:clean
	@rm -f $(NAME)

re: fclean all	