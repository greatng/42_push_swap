/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:35:33 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/01 16:56:30 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
//mode 0 = heap memory, mode 1 = stack memory

static void	check_double(t_stack *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->a[i] == stack->a[j++])
				error(1, NULL, stack);
		}
		i++;
	}
}

static void	to_stack(char **nbr, int size, int mode, t_stack *stack)
{
	int		i;
	char	*check;

	stack->a = ft_calloc(size, sizeof(int));
	i = mode - 1;
	while (nbr[++i])
	{
		stack->a[i - mode] = ft_atoi(nbr[i]);
		check = ft_itoa(stack->a[i - mode]);
		if (ft_strncmp(check, nbr[i] \
			, ft_strlen(nbr[i])))
		{
			free(check);
			error(1, NULL, stack);
		}
		free(check);
	}
	i = 0;
	if (!mode)
		free_all(nbr);
	check_double(stack, size);
	stack->b = ft_calloc(size, sizeof(int));
	stack->size_a = size;
	stack->size_b = 0;
	deter_algo(stack);
}

static int	check_digit(char **nbr, size_t n)
{
	size_t	i;
	size_t	j;

	i = n;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i][j])
		{
			if (nbr[i][j] == '-')
				j++;
			if (!ft_isdigit(nbr[i][j]))
				error(n, nbr, NULL);
			j++;
		}
		i++;
	}
	return (i - n);
}

static void	check_invalid(int argc, char **argv)
{
	char	*check;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			check = ft_strtrim(argv[i], " ");
			if (!check[0])
			{
				free(check);
				error(1, NULL, NULL);
			}
			free(check);
			i++;
		}
	}
}

void	check_arg(int argc, char **argv, t_stack *stack)
{
	char	**nbr;
	char	*check;
	int		size;
	int		mode;

	check_invalid(argc, argv);
	if (argc == 2)
	{
		nbr = ft_split(argv[1], ' ');
		mode = 0;
	}
	else
	{
		nbr = argv;
		mode = 1;
	}
	size = check_digit(nbr, mode);
	to_stack(nbr, size, mode, stack);
}
