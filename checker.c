#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    t_stack *current;

    if (!stack || !stack->next)
        return 1;
        
    current = stack;
    while (current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

char	*ft_read_until_newline(int fd)
{
	char	*buffer;
	char	c;
	int		i;
	int		bytes_read;

	buffer = malloc(1024 * sizeof(char));
	i = 0;
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, &c, 1);
	while (bytes_read > 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break ;
		bytes_read = read(fd, &c, 1);
	}
	buffer[i] = '\0';
	if (bytes_read <= 0 && i == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int   get_next_line(t_stack **a,t_stack **b)
{
    char *action;

    action = ft_read_until_newline(0);
    if (!action)
        return (0);
    if (!ft_strncmp(action,"ra\n",3))
        return (checker_rotate_a(a),free(action),1);
    else if (!ft_strncmp(action,"rb\n",3))
		return(checker_rotate_a(a),free(action),1); 
    else if (!ft_strncmp(action,"rr\n",3))
		return (checker_rotate_a_b(a,b),free(action),1);
	else if (!ft_strncmp(action,"sa\n",3))
		return (checker_swap_a(a),free(action),1);
	else if (!ft_strncmp(action,"sb\n",3))
		return (checker_swap_b(b),free(action),1);
	else if (!ft_strncmp(action,"ss\n",3))
		return (checker_swap_a_b(a,b),free(action),1);
	else if (!ft_strncmp(action,"pa\n",3))
		return (checker_ft_push_to_a(a,b),free(action),1);
	else if (!ft_strncmp(action,"pb\n",3))
		return (checker_ft_push_to_b(a,b),free(action),1);
	else if (!ft_strncmp(action,"rra\n",4))
		return (checker_r_rotate_a(a),free(action),1);
	else if (!ft_strncmp(action,"rrb\n",4))
		return (checker_r_rotate_b(a),free(action),1);
	else if (!ft_strncmp(action,"rrr\n",4))
		return (checker_rr_rotate(a,b),free(action),1);	
	else 
	{
		free(action);
		free_stack(a);
		free_stack(b);
		write(2, "Error\n",6);
		exit(1);
	}
	
}


int main(int argc,char *argv[])
{
    t_stack *a = NULL;
    t_stack *b = NULL;
	/* TODO 
	 	1) fix sa ss when 2 numbers in checker 

	*/
	// printf("%s\n",argv[1]);
	// if (argc < 2)
	// 	return (1);
    stack_init(&a,argv + 1);
	// // checker_rotate_a(&a);
	while(a)
	{
		printf("%d\n",a->value);
		a = a->next;
	}
	// 	// write(1, "",1);
	// while(get_next_line(&a,&b));
	// // 	// write(1, "",1);
	// if(is_sorted(a) && !b)
	// 	write(1,"OK\n",3);
	// else
	// 	write(1,"KO\n",3);
	// free_stack(&a);
    // free_stack(&b);
	// exit(0);
}
