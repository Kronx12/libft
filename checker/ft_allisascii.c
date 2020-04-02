/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allisascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:35:37 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 11:56:37 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_boolean	ft_allisascii(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isascii(str[i]))
			return (FALSE);
	return (TRUE);
}
