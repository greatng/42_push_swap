/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deter_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:13:10 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 17:06:58 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//choose algo from stack size

void	deter_algo(t_stack *stack)
{
	if (is_sorted(stack))
		return ;
	stack->sub = ft_calloc(sizeof(int), stack->size_a);
	deep_copy(stack->sub, stack->a, stack->size_a);
	deep_copy_index(stack->a, stack->sub, stack->size_a);
	free(stack->sub);
	if (stack->size_a <= 5)
		small_sort(stack);
	else if (stack->size_a <= 210)
		my_sort(stack);
	else
		radix_sort(stack);
}
