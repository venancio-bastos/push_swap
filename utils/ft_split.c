/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:02:03 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/15 15:22:11 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_words(char const *s, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			total++;
		i++;
	}
	return (total);
}

char	*copy_next_word(char const *s, char c, int *i)
{
	int		start;
	int		len;
	char	*word;
	int		j;

	while (s[*i] == c)
		(*i)++;
	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	len = *i - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

void	free_split(char **arr, int index)
{
	int	j;

	j = 0;
	while (j < index)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**arr;

	arr = malloc(sizeof(char *) * (get_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		arr[x] = copy_next_word(s, c, &i);
		if (!arr[x])
		{
			free_split(arr, x);
			return (NULL);
		}
		x++;
	}
	arr[x] = NULL;
	return (arr);
}