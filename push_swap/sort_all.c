/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:53 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:34:30 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **head, int size)
{
	int			i;
	int			n;
	t_list		*tmp;

	i = 0;
	tmp = *head;
	n = tmp->value;
	while (i < size)
	{
		if (n > tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}

int	find_max(t_list	**head, int size)
{
	int			i;
	int			n;
	t_list		*tmp;

	i = 0;
	tmp = *head;
	if (!*head)
		return (0);
	n = tmp->value;
	while (i < size)
	{
		if (n < tmp->value)
			n = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (n);
}

void	sort_3(t_ab	*stack)
{
	int			min;
	int			max;
	t_list		*tmp;

	tmp = stack->a;
	min = find_min(&stack->a, stack->a_size);
	max = find_max(&stack->a, stack->a_size);
	while (check_sort(&stack->a))
	{
		if (tmp->value == max)
		{
			rotate(stack, 'a');
			tmp = stack->a;
		}
		if (tmp->value < tmp->next->value && tmp->next->value == max)
		{
			rev_rotate(stack, 'a');
			tmp = stack->a;
		}
		if (tmp->value > tmp->next->value && tmp->next->value == min)
		{
			swap(stack, 'a');
			tmp = stack->a;
		}
	}
}

void	sort_5(t_ab *stack)
{
	int			min;
	int			max;

	min = find_min(&stack->a, stack->a_size);
	max = find_max(&stack->a, stack->a_size);
	while (stack->a_size != 3)
	{
		if (stack->a->value == max || stack->a->value == min)
			rotate(stack, 'a');
		else
			push(stack, 'b');
	}
	sort_3(stack);
	rev_rotate(stack, 'a');
	if (stack->b->value < stack->b->next->value)
		swap(stack, 'b');
	while (stack->b)
	{
		while ((stack->b->value > stack->a->value)
			|| stack->a->prev->value > stack->b->value)
			rev_rotate(stack, 'a');
		push(stack, 'a');
	}
	while (check_sort(&stack->a))
		rev_rotate(stack, 'a');
}

void	sort_all(t_ab *stack, int argc)
{
	if (argc == 3)
		swap(stack, 'a');
	else if (argc == 4)
		sort_3(stack);
	else if (argc <= 6)
		sort_5(stack);
	else if (argc > 6)
		sort_max(stack, argc);
}
