/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:09:57 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:39 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_ulitoa_base(unsigned long long val, char *base)
{
	char				*str;
	int					res_len;
	unsigned int		base_len;
	unsigned long long	copy;

	base_len = ft_strlen(base);
	copy = val;
	res_len = 0;
	while (++res_len && copy >= base_len)
		copy /= base_len;
	if (!(str = malloc(res_len + 2)))
		return (NULL);
	str[res_len] = '\0';
	while (val >= base_len && --res_len)
	{
		str[res_len] = base[val % base_len];
		val /= base_len;
	}
	str[--res_len] = base[val];
	return (str);
}
