/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:00:19 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/25 15:22:43 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	move_down(int *stack, int size)
{
	while (--size)
		stack[size] = stack[size - 1];
}

static void	move_up(int *stack, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		stack[i - 1] = stack[i];
		i++;
	}
}

char	*pb(t_stack *stack)
{
	int	tmp;

	if (stack->size_a)
	{
		tmp = stack->a[0];
		move_up(stack->a, stack->size_a);
		stack->size_a--;
		stack->size_b++;
		move_down(stack->b, stack->size_b);
		stack->b[0] = tmp;
	}
	return ("pb");
}

char	*pa(t_stack *stack)
{
	int	tmp;

	if (stack->size_b)
	{
		tmp = stack->b[0];
		move_up(stack->b, stack->size_b);
		stack->size_b--;
		stack->size_a++;
		move_down(stack->a, stack->size_a);
		stack->a[0] = tmp;
	}
	return ("pa");
}
