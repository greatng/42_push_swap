/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:14:10 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/27 21:14:55 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define ERROR_EXIT 1
# define CLEAN_EXIT 0
# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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
void	free_all(char **nbr);
void	free_stack(t_stack *stack);
void	error(int mode, char **nbr);
void	clean_exit(void);

int		get_instruction(t_stack *s);
int		is_sorted(t_stack *stack);

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