/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:48:48 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/04 06:43:00 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_realloc(char *str, int size)
{
	size_t	count;
	char	*newstr;

	count = 0;
	if (!str)
		return (NULL);
	newstr = (char *)ft_calloc((ft_strlen(str) + size + 1), sizeof(*newstr));
	if (!newstr)
		return (NULL);
	while (count < (ft_strlen(str) + size) && str[count])
	{
		newstr[count] = str[count];
		count++;
	}
	newstr[count] = '\0';
	free(str);
	return (newstr);
}
