/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:48:48 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/03 03:03:28 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_realloc(char *str, int size)
{
	size_t	count;
	char	*nstr;

	count = 0;
	if (!str)
		return (NULL);
	if (!(nstr = ft_calloc(ft_strlen(str) + size + 1, sizeof(char))))
		return (NULL);
	while (count < (ft_strlen(str) + size) && str[count])
	{
		nstr[count] = str[count];
		count++;
	}
	nstr[count] = '\0';
	free(str);
	return (nstr);
}
