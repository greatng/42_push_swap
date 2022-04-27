/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:49:58 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 16:15:05 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	is_sorted(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		min;

	i = 0;
	if (stack->size_a == 0)
		return (0);
	else if (stack->size_a == 1)
		return (1);
	while (i++ < stack->size_a - 1)
	{
		min = stack->a[i - 1];
		j = i - 1;
		while (++j < stack->size_a)
		{
			if (min > stack->a[j])
				return (0);
		}
	}
	return (1);
}
