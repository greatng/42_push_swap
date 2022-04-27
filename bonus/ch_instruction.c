/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:44 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 21:13:50 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	cmp_instruction2(t_stack *s, char *ret, int len)
{
	if (!ft_strncmp("sa\n", ret, len))
		sa(s);
	else if (!ft_strncmp("sb\n", ret, len))
		sb(s);
	else if (!ft_strncmp("ss\n", ret, len))
		ss(s);
	else
		return (0);
	return (1);
}

static int	cmp_instruction1(t_stack *s, char *ret)
{
	int	len;

	len = ft_strlen(ret);
	if (!ft_strncmp("pa\n", ret, len))
		pa(s);
	else if (!ft_strncmp("pb\n", ret, len))
		pb(s);
	else if (!ft_strncmp("ra\n", ret, len))
		ra(s);
	else if (!ft_strncmp("rb\n", ret, len))
		rb(s);
	else if (!ft_strncmp("rr\n", ret, len))
		rr(s);
	else if (!ft_strncmp("rra\n", ret, len))
		rra(s);
	else if (!ft_strncmp("rrb\n", ret, len))
		rrb(s);
	else if (!ft_strncmp("rrr\n", ret, len))
		rrr(s);
	else
		return (cmp_instruction2(s, ret, len));
	return (1);
}

//cmp_status 0 == no instruction, status 1 normal, status 2 end of instruction

int	get_instruction(t_stack *s)
{
	char	*ret;
	int		cmp_status;

	while (1)
	{
		ret = get_next_line(STDIN_FILENO);
		if (!ret)
			return (1);
		cmp_status = cmp_instruction1(s, ret);
		free(ret);
		if (!cmp_status)
			return (0);
	}
}
