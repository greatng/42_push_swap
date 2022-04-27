/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:23:21 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/26 20:13:51 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	radix_sort(t_stack *s)
{
	int	i;
	int	pass;
	int	size;

	i = 0;
	size = s->size_a;
	pass = 0;
	while (!is_sorted(s))
	{
		while (i < size)
		{
			if ((s->a[0] >> pass) & 1)
				ft_printf("%s\n", ra(s));
			else if (i != size -1)
				ft_printf("%s\n", pb(s));
			i++;
		}
		i = 0;
		pass++;
		while (s->size_b)
			ft_printf("%s\n", pa(s));
	}
}
