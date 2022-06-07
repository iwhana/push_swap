/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:19 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:30:36 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mid(int *arr, int argc)
{
	int	min;
	int	max;
	int	mid;

	min = arr[0];
	max = arr[argc - 2];
	mid = arr[(argc - 1) / 2];
	return (mid);
}

void	sort_arr(int *arr, int argc)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc - 1)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	*make_arr(t_ab *stack, int argc)
{
	int			i;
	int			*arr;
	t_list		*tmp;

	i = 0;
	tmp = stack->a;
	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	while (i < argc - 1)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	sort_arr(arr, argc);
	return (arr);
}
