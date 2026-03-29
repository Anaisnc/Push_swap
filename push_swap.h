/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaiscourt <ancourt@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:59:07 by ancourt           #+#    #+#             */
/*   Updated: 2026/03/29 15:31:20 by anaiscourt       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;
typedef struct s_benchmark
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
}	t_benchmark;
typedef struct s_config
{
	t_strategy		strategy;
	bool			bench_mode;
	float			disorder;
	t_benchmark		stats;
	char			*strategy_name;
}	t_config;
int			count_numbers(int argc, char **argv, int start);
int			parse_args(int argc, char **argv, t_stack *a, int start);
t_strategy	parse_strategy_flag(char *flag);
bool		parse_bench_flag(char *flag);
int			parse_all_flags(int argc, char **argv, t_config *cfg);
void		validate_input(t_stack *a);
bool		has_duplicates(t_stack *a);
bool		is_valid_number(char *str);
size_t		count_words(const char *s, char c);
char		*dup_word(const char *s, size_t start, size_t end);
char		**ft_split(const char *s, char c);
void		free_split(char **res, size_t k);
int			fill_split(char **res, const char *s, char c, size_t words);

void		assign_index(t_stack *a);
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			compute_disorder(t_stack *a);
t_stack		*init_stack(void);
t_node		*create_node(int value);
void		stack_add_bottom(t_stack *stack, int value);
int			stack_size(t_stack *stack);
t_node		*get_node_at_pos(t_stack *stack, int pos);
t_node		*stack_get_bottom(t_stack *stack);
int			find_min_index(t_stack *stack);
int			find_max_index(t_stack *stack);
int			find_position_of_index(t_stack *stack, int index);
bool		is_sorted(t_stack *stack);
bool		is_reverse_sorted(t_stack *stack);
void		free_stack(t_stack *stack);
void		free_both_stacks(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b, t_benchmark *stats);
void		pb(t_stack *a, t_stack *b, t_benchmark *stats);
void		sa(t_stack *a, t_benchmark *stats);
void		sb(t_stack *b, t_benchmark *stats);
void		ss(t_stack *a, t_stack *b, t_benchmark *stats);
void		ra(t_stack *a, t_benchmark *stats);
void		rb(t_stack *b, t_benchmark *stats);
void		rr(t_stack *a, t_stack *b, t_benchmark *stats);
void		rra(t_stack *a, t_benchmark *stats);
void		rrb(t_stack *b, t_benchmark *stats);
void		rrr(t_stack *a, t_stack *b, t_benchmark *stats);
void		sort_stack(t_stack *a, t_stack *b, t_config *cfg);
void		sort_two(t_stack *a, t_benchmark *stats);
void		sort_three(t_stack *a, t_benchmark *stats);
void		sort_five(t_stack *a, t_stack *b, t_benchmark *stats);
void		adaptive_sort(t_stack *a, t_stack *b, t_config *cfg);
void		choose_by_disorder(t_stack *a, t_stack *b, t_config *cfg);
void		medium_sort(t_stack *a, t_stack *b, t_benchmark *stats);
void		complex_sort(t_stack *a, t_stack *b, t_benchmark *stats);
void		adaptive_sort(t_stack *a, t_stack *b, t_config *cfg);
void		turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats);
void		lis_turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats);
void		push_all_except_three(t_stack *a, t_stack *b, t_benchmark *stats);
void		assign_current_position(t_stack *stack);
void		assign_target_position(t_stack *a, t_stack *b);
int			*find_lis(t_stack *a, int *lis_length);
void		push_except_lis(t_stack *a, t_stack *b, t_benchmark *stats);
void		calculate_cost(t_stack *a, t_stack *b);
void		execute_cheapest_move(t_stack *a, t_stack *b, t_benchmark *stats);
void		final_rotate_to_min(t_stack *a, t_benchmark *stats);
void		chunk_algorithm(t_stack *a, t_stack *b, int num_chunks, t_benchmark *stats);
int			calculate_optimal_chunks(int size);
void		get_chunk_range(int id, int chunks, int size, int *min, int *max);
bool		is_in_chunk(int index, int min, int max);
void		push_chunk_to_b(t_stack *a, t_stack *b, int min, int max, t_benchmark *stats);
int			find_max_position(t_stack *b);
void		optimal_rotation_b(t_stack *b, int pos, t_benchmark *stats);
void		merge_back_from_b(t_stack *a, t_stack *b, t_benchmark *stats);
int			calculate_optimal_chunks(int size);
void		push_chunk_to_b(t_stack *a, t_stack *b, int min, int max, t_benchmark *stats);
void		merge_back_from_b(t_stack *a, t_stack *b, t_benchmark *stats);
void		radix_algorithm(t_stack *a, t_stack *b, t_benchmark *stats);
void		init_benchmark(t_benchmark *stats);
void		init_config(t_config *cfg);
void		reset_stats(t_benchmark *stats);
void		print_benchmark(t_config *cfg);
void		print_operations_count(t_benchmark *stats);
char		*get_complexity_class(t_strategy strategy);
void		error_exit(char *message);
void		error_free_exit(t_stack *a, t_stack *b, char *message);
void		write_error(char *message);
void		ft_putnbr(int n);

#endif