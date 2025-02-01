/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 09:48:46 by rbaldin           #+#    #+#             */
/*   Updated: 2025/01/30 11:14:30 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	digit_only(const char *str);

static	int	*numbers_parsing(int argc, char *argv[], int *size);

static	int	*numbers_parsing2(char **argv, int *size);

static	int	duplicated(int  *nums, int *size);

t_stack	*input_checking(int argc, char **argv)
{
	int	*nums;
	t_stack	*stacka;
	int	size;
	int	*size_ptr;

	size = 0;
	size_ptr = &size;
	nums = NULL;
	if (argc > 2)
		nums = numbers_parsing(argc, argv, size_ptr);
	else if (argc == 2)
		nums = numbers_parsing2(argv, size_ptr);
	if (!nums || duplicated(nums, size_ptr))
	{
		free(nums);
		nums = NULL;
		return (NULL);
	}
	stacka = stack_initializing(nums, size_ptr);
	free(nums);
	if (!stacka)
		return (NULL);
	return (stacka);
}

static	int	*numbers_parsing(int argc, char *argv[], int *size)
{
	int	*nums;
	int	i;

	*size = 0;
	i = 1;
	while (i < argc)
	{
		if (!digit_only(argv[i]))
			return (NULL);
		i++;
	}
	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		nums[*size] = ft_atoi(argv[i]);
		(*size)++;
		i++;
	}
	return (nums);
}

static	int	*split_freeing(char **split)
{
	int	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static	int	*numbers_parsing2(char **argv, int *size)
{
	int	*nums;
	int	*nums_start;
	char	**split_nums;
	char	**split_start;

	split_nums = ft_split(argv[1], ' ');
	if (!split_nums)
		return (NULL);
	split_start = split_nums;
	while (*split_nums)
		if (!digit_only(*split_nums++))
			return (split_freeing(split_start));
	*size = split_nums - split_start;
	if (*size <= 0)
		return (split_freeing(split_start));
	nums = malloc(sizeof(int) * (*size));
	if (!nums)
		return (split_freeing(split_start));
	split_nums = split_start;
	nums_start = nums;
	while (split_nums < split_start + *size)
		*nums++ = ft_atoi(*split_nums++);
	split_freeing(split_start);
	return (nums_start);
}

static	int	duplicated(int	*nums, int *size)
{
	int	i;
	int	j;

	j = 0;
	while (j < *size - 1)
	{
		i = j + 1;
		while (i < *size)
		{
			if (nums[j] == nums[i])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static	int	digit_only(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
