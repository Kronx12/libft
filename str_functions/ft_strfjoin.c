/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 02:08:26 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 12:26:43 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strfjoin(char *s1, char *s2, int j)
{
	char	*r;
	char	*res;
	char	*sa;
	char	*sb;

	sa = (char *)s1;
	sb = (char *)s2;
	if (!(r = ft_calloc(ft_strlen(sa) + ft_strlen(sb) + 1, sizeof(char))))
		return (NULL);
	res = r;
	while (*sa != '\0')
		*res++ = *sa++;
	while (*sb != '\0')
		*res++ = *sb++;
	*res = '\0';
	if (j >= 1)
		free(s1);
	if (j > 1)
		free(s2);
	return (r);
}
