/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:37:07 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:37:09 by gbaud            ###   ########.fr       */
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
