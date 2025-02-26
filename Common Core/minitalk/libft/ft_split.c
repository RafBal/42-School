/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaldin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:33:28 by rbaldin           #+#    #+#             */
/*   Updated: 2024/11/08 15:09:47 by rbaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_subs_count(char const *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (s[i])
	{
		if (!word && s[i] != c)
		{
			word = 1;
			j++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (j);
}

static char	**ft_free_string(char **part, int k)
{
	while (--k >= 0)
		free(part[k]);
	free(part);
	return (NULL);
}

static char	**ft_assign(char **part, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[i] && s[i] != c)
				i++;
			part[k++] = ft_substr(s, j, i - j);
			if (!part[k - 1])
				return (ft_free_string(part, k));
		}
		else
			i++;
	}
	part[k] = NULL;
	return (part);
}

char	**ft_split(char const *s, char c)
{
	char	**part;

	if (!s)
		return (NULL);
	part = (char **)malloc((ft_subs_count(s, c) + 1) * sizeof(char *));
	if (!part)
		return (NULL);
	return (ft_assign(part, s, c));
}

/* Uncomment for testing purposes
#include <stdio.h>

int main(void)
{
    char **split;
    int i;

    split = ft_split(" hello world ", ' ');
    if (split)
    {
        for (i = 0; split[i] != NULL; i++)
            printf("%s\n", split[i]);
        ft_free_string(split, i);
    }
    return 0;
}
*/
