/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <ablabib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:33:35 by ablabib           #+#    #+#             */
/*   Updated: 2024/11/03 18:12:46 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stddef.h>
#include <stdlib.h>
#include <stddef.h>

static int	count_words(char const *s, char c)
{
	size_t	counter;
	size_t	i;
	int		flag;

	flag = 1;
	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			counter++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (counter);
}

static int	free_allocate(char **ptr, int pos)
{
	while (pos--)
	{
		free(ptr[pos]);
	}
	free(ptr);
	return (1);
}

static int	allocate_words(char **ptr, char *s, char c)
{
	unsigned int	i;
	size_t			len;
	char			*word;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			word = ft_substr(s - len, 0, len);
			if (!word)
				return (free_allocate(ptr, i));
			ptr[i++] = word;
		}
	}
	ptr[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**ptr;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	ptr[words] = NULL;
	if (allocate_words(ptr, (char *)s, c))
		return (NULL);
	return (ptr);
}

// static size_t count_words(char const *s, char c)
// {
//     size_t count;
//     int in_word;

//     count = 0;
//     in_word = 0;
//     if (!s)
//         return (0);
//     while (*s)
//     {
//         if (*s != c && !in_word)
//         {
//             in_word = 1;
//             count++;
//         }
//         else if (*s == c)
//             in_word = 0;
//         s++;
//     }
//     return (count);
// }

// static char *get_next_word(char const *str, char c, size_t *len, size_t *offset)
// {
//     char const *start;
//     char *word;

//     *len = 0;
//     while (str[*offset] == c && str[*offset])
//         (*offset)++;
//     start = str + *offset;
//     while (str[*offset] != c && str[*offset])
//     {
//         (*len)++;
//         (*offset)++;
//     }
//     word = ft_substr(start, 0, *len);
//     return (word);
// }

// static int free_allocate(char **ptr, int i)
// {
//     if (!ptr)
//         return (-1);
//     while (i >= 0)
//     {
//         if (ptr[i])
//             free(ptr[i]);
//         i--;
//     }
//     free(ptr);
//     return (-1);
// }

// static int allocate_words(char **ptr, char const *s, char c)
// {
//     unsigned int i;
//     size_t len;
//     size_t offset;
//     char *word;

//     i = 0;
//     offset = 0;
//     while (s[offset])
//     {
//         word = get_next_word(s, c, &len, &offset);
//         if (!word && i > 0)
//             return (free_allocate(ptr, i - 1));
//         if (!word)
//             return (free_allocate(ptr, -1));
//         if (len > 0)
//             ptr[i++] = word;
//         else
//             free(word);
//     }
//     ptr[i] = NULL;
//     return (0);
// }

// char **ft_split(char const *s, char c)
// {
//     char **result;
//     size_t word_count;

//     if (!s)
//         return (NULL);
//     word_count = count_words(s, c);
//     if (word_count == 0)
//         return (NULL);
//     result = (char **)malloc(sizeof(char *) * (word_count + 1));
//     if (!result)
//         return (NULL);
//     if (allocate_words(result, s, c) == -1)
//         return (NULL);
//     return (result);
// }