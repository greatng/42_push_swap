/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:23:21 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/02 11:03:45 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static int	is_radix_sorted(t_stack *s, int pass)
{
	int	i;

	i = -1;
	while (++i < s->size_a)
	{
		if (((s->a[i] >> pass) & 1))
			return (0);
	}
	return (1);
}

void	radix_sort(t_stack *s)
{
	int	i;
	int	pass;
	int	size;

	size = s->size_a;
	pass = 0;
	while (!is_sorted(s))
	{
		i = 0;
		while (i < size)
		{
			if ((s->a[0] >> pass) & 1)
				ft_printf("%s\n", ra(s));
			else if (i != size - 1)
				ft_printf("%s\n", pb(s));
			if (is_radix_sorted(s, pass))
				break ;
			i++;
		}
		pass++;
		while (s->size_b)
			ft_printf("%s\n", pa(s));
	}
}
