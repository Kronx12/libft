/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:42:17 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 13:20:30 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*r;
	char			*t;
	unsigned int	i;

	i = 0;
	t = (char *)s;
	if (!(r = malloc(sizeof(char) * (ft_strlen(t) + 1))))
		return (NULL);
	while (t[i] != '\0')
	{
		r[i] = f(i, t[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
