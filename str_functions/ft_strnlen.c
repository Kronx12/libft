/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:18:08 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:41:18 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strnlen(const char *s, size_t size)
{
	size_t i;

	i = 0;
	while (size >= i && s[i] != '\0')
		i++;
	return (i);
}
