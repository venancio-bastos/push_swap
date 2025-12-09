/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:35:25 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/09 13:38:40 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i = 0;
	while (i < ac)
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		printf("Final result: %d\n", ft_atoi(av[i]));
		i++;
	}
	return (0);
}