/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:04:16 by rbaldin           #+#    #+#             */
/*   Updated: 2025/02/10 15:48:35 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_proint(const char *a)
{
	int		v;
	int		signal;
	bool	digit_found;

	v = 0;
	signal = 0;
	digit_found = false;
	while (*a == ' ' || (*a >= 9 && *a <= 13))
		a++;
	if (*a == '-')
	{
		signal = 1;
		a++;
	}
	else if (*a == '+')
		a++;
	while (ft_isdigit(*a))
	{
		digit_found = true;
		if ((v > INT_MAX / 10) || (v == INT_MAX / 10 && (*a - '0')
				> (INT_MAX % 10 + signal)))
			return (false);
		v = v * 10 + (*a++ - '0');
	}
	return (digit_found);
}
// Note 1: (v > INT_MAX / 10) -> e.g.: 214748365 > 214748364;
// There will be 214748365 plus one digit inside the loop, thus an overflow.
// Note 2: INT_MAX % 10 + signal -> e.g.: 7 + (1 if negative or 0 if positive)

static	int	error_message(void)
{
	ft_putendl_fd("Error", 2);
	return (1);
}

static	bool	out_limit_verifying(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_proint(av[i]))
			return (true);
	}
	return (false);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (error_message());
	if (argc >= 2 && out_limit_verifying(argc, argv))
		return (error_message());
	stack_a = input_checking(argc, argv);
	if (!stack_a)
		return (error_message());
	stack_b = null_stack_initializing();
	if (!stack_b)
	{
		stack_freeing(&stack_a);
		return (error_message());
	}
	push_swap(&stack_a, &stack_b);
	stack_freeing(&stack_a);
	stack_freeing(&stack_b);
	return (0);
}
