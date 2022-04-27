/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:39:16 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 21:24:50 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 1)
		clean_exit();
	stack = ft_calloc(1, sizeof(t_stack));
	check_arg(argc, argv, stack);
	free_stack(stack);
	clean_exit();
}
