/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:00:58 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 01:35:42 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

char	*rra(t_stack *stack)
{
	int	tmp;
	int	i;

	if (!stack->size_a)
		return ("");
	tmp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	return ("rra");
}

char	*rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	if (!stack->size_b)
		return ("");
	tmp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	return ("rrb");
}

char	*rrr(t_stack *stack)
{
	int	tmp;
	int	i;

	if (!stack->size_a || !stack->size_b)
		return ("");
	tmp = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	tmp = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	return ("rrr");
}
