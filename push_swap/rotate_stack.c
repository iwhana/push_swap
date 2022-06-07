/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:22:46 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:34:05 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rot(t_list **head)
{
	t_list	*second;

	second = (*head)->next;
	(*head) = second;
}

void	rotate(t_ab *stack, char c)
{
	if (c == 'a' && stack->a)
	{
		do_rot(&stack->a);
		write(1, "ra\n", 3);
	}
	if (c == 'b' && stack->b)
	{
		do_rot(&stack->b);
		write(1, "rb\n", 3);
	}
	if (c == 'r' && stack->a && stack->b)
	{
		do_rot(&stack->a);
		do_rot(&stack->b);
		write(1, "rr\n", 3);
	}
}

static void	do_rev_rot(t_list **head, int stack_size)
{
	int			j;
	t_list		*tmp;

	j = 0;
	tmp = *head;
	while (j < stack_size - 1)
	{
		tmp = tmp->next;
		j++;
	}
	(*head) = tmp;
}

void	rev_rotate(t_ab *stack, char c)
{
	if (c == 'a' && stack->a)
	{
		do_rev_rot(&stack->a, stack->a_size);
		write(1, "rra\n", 4);
	}
	if (c == 'b' && stack->b)
	{
		do_rev_rot(&stack->b, stack->b_size);
		write(1, "rrb\n", 4);
	}
	if (c == 'r' && stack->a && stack->b)
	{
		do_rev_rot(&stack->a, stack->a_size);
		do_rev_rot(&stack->b, stack->b_size);
		write(1, "rrr\n", 4);
	}
}
