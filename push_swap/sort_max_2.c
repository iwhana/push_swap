/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:23:04 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:35:34 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

void	rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score)
{
	while (*rot_b_score > 0 && *rot_a_score > 0)
	{
		rotate(stack, 'r');
		--*rot_b_score;
		--*rot_a_score;
	}
	while (*rot_a_score > 0)
	{
		rotate(stack, 'a');
		--*rot_a_score;
	}
	while (*rot_b_score > 0)
	{
		rotate(stack, 'b');
		--*rot_b_score;
	}
}

void	rev_rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score)
{
	while (*rot_b_score < 0 && *rot_a_score < 0)
	{
		rev_rotate(stack, 'r');
		++*rot_b_score;
		++*rot_a_score;
	}
	while (*rot_a_score < 0)
	{
		rev_rotate(stack, 'a');
		++*rot_a_score;
	}
	while (*rot_b_score < 0)
	{
		rev_rotate(stack, 'b');
		++*rot_b_score;
	}
}

void	rot_and_push_ba(t_ab *stack, t_list *min_score, int position)
{
	int	rot_a_score;
	int	rot_b_score;

	rot_a_score = sum_rot_a(stack, min_score->value);
	if (position < stack->b_size - position)
		rot_b_score = position;
	else
		rot_b_score = position - stack->b_size;
	if (rot_b_score > 0 || rot_a_score > 0)
		rot_ba(stack, &rot_a_score, &rot_b_score);
	if (rot_b_score < 0 || rot_a_score < 0)
		rev_rot_ba(stack, &rot_a_score, &rot_b_score);
	push(stack, 'a');
}

void	rot_or_revr(t_ab *stack)
{
	t_list	*tmp;
	int		i;
	int		max_a;

	i = 0;
	tmp = stack->a;
	max_a = find_max(&stack->a, stack->a_size);
	while (i < stack->a_size && tmp->value < max_a)
	{
		tmp = tmp->next;
		i++;
	}
	while (check_sort(&stack->a))
	{
		if (i < stack->a_size - i)
			rotate(stack, 'a');
		else
			rev_rotate(stack, 'a');
	}
}
