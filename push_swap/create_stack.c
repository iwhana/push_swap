/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 21:16:21 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/19 01:51:57 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_ab *stack)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	stack->a = NULL;
	stack->b = NULL;
	stack->a_size = 0;
	stack->b_size = 0;
}

t_list	*put_value(int data)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
	{
		free(tmp);
		return (0);
	}
	tmp->value = data;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

void	add_elem_end(t_list **a, t_list *new)
{
	t_list	*tmp;

	tmp = *a;
	if (!*a)
		*a = new;
	if (tmp)
	{
		new->next = tmp;
		new->prev = tmp->prev;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}
