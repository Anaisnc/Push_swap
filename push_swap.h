/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancourt <ancourt@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 19:59:07 by ancourt           #+#    #+#             */
/*   Updated: 2026/01/24 21:28:57 by ancourt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include "libft.h"
# include "printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}				t_stack;

#endif