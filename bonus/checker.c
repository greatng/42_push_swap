/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:12:11 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 20:41:06 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		clean_exit();
	stack = ft_calloc(1, sizeof(t_stack));
	check_arg(argc, argv, stack);
	if (get_instruction(stack))
	{
		if (is_sorted(stack) && !stack->size_b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		error(1, argv);
	clean_exit();
}
