/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:58 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:34:58 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sum_rot_a(t_ab *stack, int value)
{
	int			rot;
	t_list		*tmp;
	int			i;

	i = 1;
	rot = 0;
	tmp = stack->a;
	while (value > tmp->value || tmp->prev->value > value)
	{
		tmp = tmp->next;
		rot++;
	}
	if (rot < stack->a_size - rot)
		return (rot);
	else
		return (rot - stack->a_size);
}

void	sum_score(t_ab *stack, t_list *tmp, int position)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = sum_rot_a(stack, tmp->value);
	if (position < stack->b_size - position)
		rot_b_score = position;
	else
		rot_b_score = position - stack->b_size;
	if ((rot_a_score > 0 && rot_b_score > 0)
		|| (rot_a_score < 0 && rot_b_score < 0))
	{
		if (pos(rot_a_score) > pos(rot_b_score))
			tmp->elem_score = pos(rot_a_score);
		else
			tmp->elem_score = pos(rot_b_score);
	}
	else
		tmp->elem_score = pos(rot_b_score) + pos(rot_a_score);
}

t_list	*find_min_score(t_ab *stack, int *position)
{
	int		i;
	t_list	*tmp;
	t_list	*min_score_elem;

	i = 1;
	*position = 0;
	tmp = stack->b->next;
	min_score_elem = stack->b;
	while (i < stack->b_size)
	{
		if (tmp->elem_score < min_score_elem->elem_score && tmp)
		{
			*position = i;
			min_score_elem = tmp;
		}
		if (tmp->elem_score < min_score_elem->elem_score
			&& tmp->value < min_score_elem->value && tmp)
		{
			*position = i;
			min_score_elem = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (min_score_elem);
}

void	next_step(t_ab *stack)
{
	t_list	*tmp;
	t_list	*min_score;
	int		i;
	int		position;

	i = 0;
	tmp = stack->b;
	while (i < stack->b_size)
	{
		sum_score(stack, tmp, i);
		tmp = tmp->next;
		i++;
	}
	min_score = find_min_score(stack, &position);
	rot_and_push_ba(stack, min_score, position);
}

void	sort_max(t_ab *stack, int argc)
{
	int	*sort_arr;
	int	mid;
	int	min;
	int	max;

	sort_arr = make_arr(stack, argc);
	mid = find_mid(sort_arr, argc);
	min = sort_arr[0];
	max = sort_arr[argc - 2];
	push_to_b(stack, min, max, mid);
	while (stack->b != NULL)
		next_step(stack);
	rot_or_revr(stack);
	free(sort_arr);
}
