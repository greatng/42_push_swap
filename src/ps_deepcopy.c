/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_deepcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:47:21 by pngamcha          #+#    #+#             */
/*   Updated: 2022/04/21 18:07:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static int	find_min(int *src, int size)
{
	int	i;
	int	min_index;
	int	min;

	i = 0;
	min_index = 0;
	min = src[0];
	while (i < size)
	{
		if (min > src[i])
		{
			min_index = i;
			min = src[i];
		}
		i++;
	}
	return (min_index);
}

void	deep_copy(int *dst, int *src, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		dst[i] = src[i];
}

//replace value to index number

void	deep_copy_index(int *dst, int *src, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp_i;
	int	min_in;

	min_in = find_min(src, size);
	dst[min_in] = 0;
	j = 0;
	while (++j < size)
	{
		tmp = INT32_MAX;
		i = -1;
		while (++i < size)
		{
			if (src[i] > src[min_in] && src[i] < tmp)
			{
				tmp = src[i];
				tmp_i = i;
			}
		}
		min_in = tmp_i;
		dst[min_in] = j;
	}
}
