/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_smallsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:14:38 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/26 23:30:27 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	try_another(t_stack *s)
{
	if (s->a[1] > s->a[2])
	{
		ft_printf("%s\n", sa(s));
		ft_printf("%s\n", rra(s));
	}
	else if (s->a[0] > s->a[2])
		ft_printf("%s\n", ra(s));
	else
		ft_printf("%s\n", sa(s));
}

static void	try_case(t_stack *s)
{
	if (is_sorted(s))
		return ;
	if (s->a[0] < s->a[1])
	{
		if (s->a[0] > s->a[2])
			ft_printf("%s\n", rra(s));
		else
		{
			ft_printf("%s\n", sa(s));
			ft_printf("%s\n", ra(s));
		}
	}
	else
		try_another(s);
}

static void	four_five(t_stack *s)
{
	int	i;

	i = 0;
	while (s->a[i] != 0)
		i++;
	if (i < s->size_a / 2)
		while (s->a[0] != 0)
			ft_printf("%s\n", ra(s));
	else
		while (s->a[0] != 0)
			ft_printf("%s\n", rra(s));
	ft_printf("%s\n", pb(s));
	if (s->size_a == 4)
	{
		i = 0;
		while (s->a[i] != 1)
			i++;
		if (i < s->size_a / 2)
			while (s->a[0] != 1)
				ft_printf("%s\n", ra(s));
		else
			while (s->a[0] != 1)
				ft_printf("%s\n", rra(s));
		ft_printf("%s\n", pb(s));
	}
}

void	small_sort(t_stack *s)
{
	if (s->size_a == 2)
	{
		ft_printf("%s\n", sa(s));
		return ;
	}
	if (s->size_a > 3)
		four_five(s);
	try_case(s);
	while (s->size_b)
		ft_printf("%s\n", pa(s));
}
