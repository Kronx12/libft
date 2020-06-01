/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 02:08:26 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:33 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strslen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strfdup(char *src, int n, int f)
{
	int		i;
	char	*src2;

	if (n < 0)
	{
		i = ft_strslen((char *)src) + 1;
		if (!(src2 = (char*)malloc((i <= BUFFER_SIZE) ? BUFFER_SIZE + 1 : i)))
			return (NULL);
		i = -1;
		while (src[++i])
			src2[i] = src[i];
	}
	else
	{
		if (!(src2 = (char*)malloc(n + 1)))
			return (NULL);
		i = -1;
		while (++i < n)
			src2[i] = src[i];
	}
	src2[i] = '\0';
	if (f == 1)
		free(src);
	return (src2);
}
