/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_my_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:59:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 02:15:06 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	last_pass(t_stack *s)
{
	int	find;
	int	move;

	find = s->size_b - 1;
	while (s->size_b)
	{
		move = 0;
		while (s->b[move] != find)
			move++;
		if (move == 1)
			do_ss(s);
		while (s->b[0] != find)
		{
			if (move < s->size_b - move)
				ft_printf("%s\n", rb(s));
			else
				ft_printf("%s\n", rrb(s));
		}
		ft_printf("%s\n", pa(s));
		find--;
	}
}

static void	last_chunk(t_stack *s, int i)
{
	int	move;

	while (s->size_a)
	{
		move = 0;
		while (s->a[move] != i && move < s->size_a)
			move++;
		if (s->a[move] != i)
		{
			i++;
			continue ;
		}
		if (move == 1)
			do_ss(s);
		while (s->a[0] != i)
		{
			if (move < s->size_a - move)
				do_rr(s);
			else
				do_rrr(s);
		}
		ft_printf("%s\n", pb(s));
		i++;
	}
}

static void	top_or_btm(t_stack *s, int *move, int *key)
{
	while (s->a[move[0]] >= key[0])
		move[0]++;
	while (s->a[move[1]] >= key[0])
		move[1]--;
	while (s->a[0] >= key[0])
	{
		if (move[0] < s->size_a - move[1])
			do_rr(s);
		else
			do_rrr(s);
	}
	ft_printf("%s\n", pb(s));
}

static void	first_pass(t_stack *s)
{
	int	size;
	int	i;
	int	move[2];
	int	key[2];

	i = 0;
	key[0] = s->size_a / 4;
	key[1] = key[0];
	while (s->size_a != key[1])
	{
		size = s->size_a;
		move[0] = 0;
		move[1] = size - 1;
		top_or_btm(s, move, key);
		i++;
		if (i == key[0])
			key[0] += key[1];
	}
	last_chunk(s, key[0] - key[1]);
}

void	my_sort(t_stack *s)
{
	first_pass(s);
	last_pass(s);
}
