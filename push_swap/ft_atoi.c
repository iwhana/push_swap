/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:36:24 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:32:15 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static void	check_digit(const char *str, int *i)
{
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
		++*i;
	}
}

static void	ft_isspace(const char *str, int *i, int *n)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		++*i;
	if (str[*i] == '-')
	{
		*n = -(*n);
		++*i;
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
	if (str[*i] == '+')
	{
		++*i;
		if (!ft_isdigit(str[*i]))
		{
			write(2, "Error\n", 6);
			exit(-1);
		}
	}
}

long int	ft_atoi(const char *str)
{
	long int	res;
	int			i;
	int			j;
	int			n;

	res = 0;
	i = 0;
	n = 1;
	ft_isspace(str, &i, &n);
	j = i;
	check_digit(str, &i);
	while (str[j] != '\0' && str[j] >= '0' && str[j] <= '9')
	{
		res = (res * 10) + (str[j] - '0');
		j++;
		if (res > 2147483647 || res < -2147483647)
			break ;
	}
	return (res * n);
}
