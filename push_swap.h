/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:59:07 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/28 15:59:20 by ancourt          ###   ########.fr       */
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

// structure pour les stats
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

int			parse_numbers(int argc, char **argv, t_stack *a, int start);
int			count_numbers(int argc, char **argv, int start);
int			parse_args(int argc, char **argv, t_stack *a, int start);
t_strategy	parse_strategy_flag(char *flag);
bool		parse_bench_flag(char *flag);
int			parse_all_flags(int argc, char **argv, t_config *cfg);
void		validate_input(t_stack *a);
bool		has_duplicates(t_stack *a);
bool		is_valid_number(char *str);
bool		is_int_overflow(char *str);

void		assign_index(t_stack *a);
int			get_index_position(t_stack *a, int value);
void		sort_values(int *values, int size);
long		ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_isspace(int c);

t_stack		*init_stack(void);
t_node		*create_node(int value);
void		stack_add_top(t_stack *stack, int value);
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
void		free_node(t_node *node);

// les operations que tu avais commencé
void		pa(t_stack *a, t_stack *b, t_benchmark *stats);
void		pb(t_stack *a, t_stack *b, t_benchmark *stats);
void		do_push(t_stack *src, t_stack *dst);
void		sa(t_stack *a, t_benchmark *stats);
void		sb(t_stack *b, t_benchmark *stats);
void		ss(t_stack *a, t_stack *b, t_benchmark *stats);
void		do_swap(t_stack *stack);
void		ra(t_stack *a, t_benchmark *stats);
void		rb(t_stack *b, t_benchmark *stats);
void		rr(t_stack *a, t_stack *b, t_benchmark *stats);
void		do_rotate(t_stack *stack);
void		rra(t_stack *a, t_benchmark *stats);
void		rrb(t_stack *b, t_benchmark *stats);
void		rrr(t_stack *a, t_stack *b, t_benchmark *stats);
void		do_reverse_rotate(t_stack *stack);

/* j'ai choisi 3 algo pour ceux qui sont demander, je te met de la doc dans le readme pour que tu comprenne un peu */

void		sort_stack(t_stack *a, t_stack *b, t_config *cfg);
void		choose_strategy(t_stack *a, t_stack *b, t_config *cfg);
void		sort_two(t_stack *a, t_benchmark *stats);
void		sort_three(t_stack *a, t_benchmark *stats);
void		sort_five(t_stack *a, t_stack *b, t_benchmark *stats);
void		simple_sort(t_stack *a, t_stack *b, t_benchmark *stats);
void		medium_sort(t_stack *a, t_stack *b, t_benchmark *stats);
void		complex_sort(t_stack *a, t_stack *b, t_benchmark *stats);
void		adaptive_sort(t_stack *a, t_stack *b, t_config *cfg);
void		choose_algo_by_disorder(t_stack *a, t_stack *b, t_config *cfg);

/* TURK+lis (se qui serq utiliser pour le simple: de ce que j'ai lu il est qssez rapide et opti pour les listes simple et est de type 0(n2)) algo  */
void		turk_algorithm(t_stack *a, t_stack *b, t_benchmark *stats);
void		push_all_except_three(t_stack *a, t_stack *b, t_benchmark *stats);
void		assign_current_position(t_stack *stack);
void		assign_target_position(t_stack *a, t_stack *b);
int			find_target_pos_in_a(t_stack *a, int b_index);

/* CHUNK(lui ne ne sais pas trop de truc sur lui mais beaucoup de personne l'utilise à l'ecole. j'ai juste mit des fonctions que je pense qu'on doit utiliser)  */
void		chunk_algorithm(t_stack *a, t_stack *b, int num_chunks, t_benchmark *stats);
int			calculate_optimal_chunks(int size);
void		push_chunk_to_b(t_stack *a, t_stack *b, int min, int max, t_benchmark *stats);
void		merge_back_from_b(t_stack *a, t_stack *b, t_benchmark *stats);

/*  RADIX (pas encore renseigner sur lui mqis guillaume et sam me l'ont proposé */
void		radix_algorithm(t_stack *a, t_stack *b, t_benchmark *stats);

// afficher les stats
void		init_benchmark(t_benchmark *stats);
void		init_config(t_config *cfg);
void		reset_stats(t_benchmark *stats);
void		print_benchmark(t_config *cfg);
void		print_operations_count(t_benchmark *stats);
char		*get_complexity_class(t_strategy strategy);
int			get_total_operations(t_benchmark *stats);

void		error_exit(char *message);
void		error_free_exit(t_stack *a, t_stack *b, char *message);
void		write_error(char *message);

#endif