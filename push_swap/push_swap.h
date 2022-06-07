/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana <iwhana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:43:53 by iwhana            #+#    #+#             */
/*   Updated: 2022/02/10 17:33:41 by iwhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				value;
	int				elem_score;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_ab
{
	struct s_list	*a;
	struct s_list	*b;
	int				a_size;
	int				b_size;
}	t_ab;

int			check_sort(t_list **head);
int			check_double(t_list **head, long int n, int size);
void		create_stack(t_ab *stack);
t_list		*put_value(int data);
void		add_elem_end(t_list **a, t_list *new);
long int	ft_atoi(const char *str);
int			find_min(t_list **head, int size);
int			find_max(t_list	**head, int size);
void		sort_3(t_ab	*stack);
void		sort_5(t_ab *stack);
void		sort_all(t_ab *stack, int argc);
void		rotate(t_ab *stack, char c);
void		rev_rotate(t_ab *stack, char c);
void		push(t_ab *stack, char c);
void		push_to_b(t_ab *stack, int min, int max, int mid);
void		swap(t_ab *stack, char c);
int			sum_rot_a(t_ab *stack, int value);
void		sum_score(t_ab *stack, t_list *tmp, int position);
t_list		*find_min_score(t_ab *stack, int *position);
void		next_step(t_ab *stack);
void		sort_max(t_ab *stack, int argc);
int			find_mid(int *arr, int argc);
void		sort_arr(int *arr, int argc);
int			*make_arr(t_ab *stack, int argc);
int			pos(int num);
void		rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score);
void		rev_rot_ba(t_ab *stack, int	*rot_a_score, int *rot_b_score);
void		rot_and_push_ba(t_ab *stack, t_list *min_score, int position);
void		rot_or_revr(t_ab *stack);

#endif
