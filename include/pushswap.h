/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:31:03 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 02:01:28 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define ERROR_EXIT 1
# define CLEAN_EXIT 0

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		*sub;
	size_t	size_a;
	size_t	size_b;
	size_t	size_sub;
}	t_stack;

void	check_arg(int argc, char **argv, t_stack *stack);
void	error(int n, char **nbr);
void	free_all(char **nbr);
void	free_stack(t_stack *stack);
void	clean_exit(void);
void	deter_algo(t_stack *stack);
void	deep_copy(int *dst, int *src, int size);
void	deep_copy_index(int *dst, int *src, int size);
void	small_sort(t_stack *stack);
void	radix_sort(t_stack *s);
void	my_sort(t_stack *s);
void	do_rr(t_stack *s);
void	do_rrr(t_stack *s);
void	do_ss(t_stack *s);
int		is_sorted(t_stack *stack);

//instruction

char	*sa(t_stack *stack);
char	*sb(t_stack *stack);
char	*ss(t_stack *stack);
char	*ra(t_stack *stack);
char	*rb(t_stack *stack);
char	*rr(t_stack *stack);
char	*rra(t_stack *stack);
char	*rrb(t_stack *stack);
char	*rrr(t_stack *stack);
char	*pa(t_stack *stack);
char	*pb(t_stack *stack);

#endif