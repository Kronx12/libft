/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 04:18:24 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 13:20:48 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *fi, const char *se, size_t len)
{
	const unsigned char	*f;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	f = (const unsigned char *)fi;
	s = (const unsigned char *)se;
	if (len == 0)
		return (0);
	while (i < len && f[i] == s[i] && f[i] != '\0')
		i++;
	if (i == len)
		i--;
	return ((unsigned char)f[i] - s[i]);
}
