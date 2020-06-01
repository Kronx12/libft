/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 01:52:07 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:41:11 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	**ft_malloc_tab(char **result, char const *str,
		char charset, int size)
{
	int k;
	int j;
	int i;

	k = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (str[i] != charset && i++ < size)
			j++;
		if (j > 0)
			k++;
		i++;
	}
	if (!(result = (char **)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	return (result);
}

static int	ft_malloc_str(char **result, char const *str,
		char charset, int size)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (str[i] != charset && i++ < size)
			j++;
		if (j > 0)
		{
			if (!(result[k++] = (char *)malloc(sizeof(char) * (j + 1))))
				return (0);
		}
		i++;
	}
	return (1);
}

static void	ft_str_str(char **result, char const *str, char charset, int size)
{
	int j;
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (str[i] != charset && i < size)
		{
			result[k][j] = str[i];
			result[k][j + 1] = '\0';
			i++;
			j++;
		}
		if (j > 0)
			k++;
		i++;
	}
	result[k] = 0;
}

char		**ft_split(char const *str, char charset)
{
	char	**result;
	int		size;
	int		i;

	size = 0;
	result = 0;
	while (str[size])
		size++;
	if (!(result = ft_malloc_tab(result, str, charset, size)))
		return (NULL);
	if (!(ft_malloc_str(result, str, charset, size)))
	{
		i = 0;
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
		return (NULL);
	}
	ft_str_str(result, str, charset, size);
	return (result);
}
