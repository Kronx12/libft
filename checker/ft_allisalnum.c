/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allisalnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:35:37 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/02 05:11:12 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_boolean	ft_allisalnum(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isalnum(str[i]))
			return (FALSE);
	return (TRUE);
}
