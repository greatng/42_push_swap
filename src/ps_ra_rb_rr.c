/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:00:58 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 01:32:57 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

char	*ra(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->a[0];
	i = 0;
	while (i < (stack->size_a) - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	return ("ra");
}

char	*rb(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->b[0];
	i = 0;
	while (i < (stack->size_b) - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	return ("rb");
}

char	*rr(t_stack *stack)
{
	int		tmp;
	size_t	i;

	tmp = stack->a[0];
	i = 0;
	while (i < (stack->size_a) - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	tmp = stack->b[0];
	i = 0;
	while (i < (stack->size_b) - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	return ("rr");
}
