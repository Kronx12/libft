/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:37:07 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 13:29:17 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strrchr_int(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return (i);
	while (i--)
		if (s[i] == c)
			return (i);
	return (0);
}
