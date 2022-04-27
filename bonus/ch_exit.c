/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:59:42 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 16:41:01 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
		if (stack->sub)
			free(stack->sub);
		free(stack);
	}
}
//mode 1 stack memmory
//mode 0 heap memmory need free

void	error(int mode, char **nbr)
{
	if (!mode)
		free_all(nbr);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(ERROR_EXIT);
}

void	clean_exit(void)
{
	exit(CLEAN_EXIT);
}
