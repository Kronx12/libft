/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:24:13 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/02 10:28:29 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_free_strs(int count, ...)
{
	va_list list;

	va_start(list, count);
	while (count--)
		free(va_arg(list, char *));
	return (1);
}
