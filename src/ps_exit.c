/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:42 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/30 16:45:07 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_all(char **nbr)
{
	size_t	i;

	i = 0;
	while (nbr[i])
		free(nbr[i++]);
	free(nbr);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		free(stack);
	}
}
//mode 1 stack memmory
//mode 0 heap memmory need free

void	error(int mode, char **nbr, t_stack *stack)
{
	if (!mode)
		free_all(nbr);
	ft_putendl_fd("Error", 2);
	free_stack(stack);
	exit(ERROR_EXIT);
}

void	clean_exit(void)
{
	exit(CLEAN_EXIT);
}
