/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_str_1d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 04:34:28 by gbaud             #+#    #+#             */
/*   Updated: 2020/09/10 09:11:58 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_debug_str_1d(char **arr)
{
	int i;

	i = -1;
	if (arr)
	{
		ft_printf("[ ");
		while (arr[++i])
		{
			ft_printf("\"%s\"", arr[i]);
			if (arr[i + 1])
				ft_printf(", ");
		}
		ft_printf(" ]\n");
	}
	else
		ft_printf("(arr) is NULL");
}
