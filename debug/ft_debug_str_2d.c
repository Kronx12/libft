/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug_str_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 04:38:42 by gbaud             #+#    #+#             */
/*   Updated: 2020/09/19 07:53:39 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_debug_str_2d(char ***arr)
{
	int i;
	int j;

	i = -1;
	ft_printf("[\n");
	while (arr[++i])
	{
		ft_printf("\t[ ");
		j = -1;
		while (arr[i][++j])
		{
			ft_printf("\"%s\"", arr[i][j]);
			if (arr[i][j + 1])
				ft_printf(", ");
		}
		ft_printf(" ]\n");
	}
	ft_printf("]\n");
}
