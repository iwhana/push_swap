/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:35 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:32:44 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_push(t_list **to, t_list **from)
{
	t_list	*tmp_from;

	tmp_from = NULL;
	if ((*from) != (*from)->next)
	{
		tmp_from = (*from)->next;
		tmp_from->prev = (*from)->prev;
		(*from)->prev->next = tmp_from;
	}
	if (!(*to))
	{
		(*from)->next = *from;
		(*from)->prev = *from;
	}
	else
	{
		(*from)->next = *to;
		(*to)->prev->next = *from;
		(*from)->prev = (*to)->prev;
		(*to)->prev = *from;
	}
	*to = *from;
	*from = tmp_from;
}

void	push(t_ab *stack, char c)
{
	if (c == 'a' && stack->b)
	{
		do_push(&stack->a, &stack->b);
		stack->a_size++;
		stack->b_size--;
		write(1, "pa\n", 3);
	}
	if (c == 'b' && stack->a)
	{
		do_push(&stack->b, &stack->a);
		stack->a_size--;
		stack->b_size++;
		write(1, "pb\n", 3);
	}
}

void	push_to_b(t_ab *stack, int min, int max, int mid)
{
	while (stack->a_size > 2)
	{
		if (stack->a->value > mid && stack->a->value != min
			&& stack->a->value != max)
		{
			push(stack, 'b');
			rotate(stack, 'b');
		}
		else if (stack->a->value <= mid && stack->a->value != min
			&& stack->a->value != max)
			push(stack, 'b');
		else
			rotate(stack, 'a');
	}
	if (stack->a->value == min)
		rotate(stack, 'a');
}

static void	do_swap(t_list **head)
{
	t_list	*second;
	int		tmp;

	tmp = (*head)->value;
	(*head)->value = (*head)->next->value;
	(*head)->next->value = tmp;
}

void	swap(t_ab *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		do_swap(&stack->a);
		write(1, "sa\n", 3);
	}
	if (c == 'b' && stack->b && stack->b->next)
	{
		do_swap(&stack->b);
		write(1, "sb\n", 3);
	}
	if (c == 's' && stack->a && stack->a->next && stack->b && stack->b->next)
	{
		do_swap(&stack->a);
		do_swap(&stack->b);
		write(1, "ss\n", 3);
	}
}
