/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ss_rr_rrr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:40:05 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 21:31:41 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	do_ss(t_stack *s)
{
	if (s->size_a && s->size_b)
	{
		if (s->a[0] > s->a[1] && s->b[0] < s->b[1])
			ft_printf("%s\n", ss(s));
		else if (s->a[0] > s->a[1])
			ft_printf("%s\n", sa(s));
		else if (s->b[0] < s->b[1])
			ft_printf("%s\n", sb(s));
	}
	else if (s->size_a)
		ft_printf("%s\n", sa(s));
	else
		ft_printf("%s\n", sb(s));
}

void	do_rr(t_stack *s)
{
	if (s->size_b)
	{
		if (s->b[0] < s->b[1])
			ft_printf("%s\n", rr(s));
		else
			ft_printf("%s\n", ra(s));
	}
	else
		ft_printf("%s\n", ra(s));
}

void	do_rrr(t_stack *s)
{
	if (s->size_b)
	{
		if (s->b[s->size_b - 1] > s->b[0])
			ft_printf("%s\n", rrr(s));
		else
			ft_printf("%s\n", rra(s));
	}
	else
		ft_printf("%s\n", rra(s));
}
