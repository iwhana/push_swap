/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:04:32 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/19 01:52:18 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_list **head)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *head;
	last = (*head)->prev;
	if (!(*head))
		return (-1);
	while (tmp != last)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_double(t_list **head, long int n, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *head;
	while (i < size)
	{
		if (tmp->value == n)
			return (1);
		tmp = tmp->next;
		i++;
	}
	if (n > 2147483647 || n < -2147483647)
		return (1);
	return (0);
}

static void	help_main(int argc, char **argv, t_ab stack)
{
	int			i;
	long int	n;
	t_list		*tmp;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			n = ft_atoi(argv[i]);
			tmp = put_value(n);
			if (!tmp || check_double(&stack.a, n, stack.a_size))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			add_elem_end(&stack.a, tmp);
			stack.a_size = i;
			i++;
		}
		if (check_sort(&stack.a))
			sort_all(&stack, argc);
	}
}

int	main(int argc, char **argv)
{
	t_ab	stack;

	create_stack(&stack);
	help_main(argc, argv, stack);
	exit(EXIT_SUCCESS);
}
