/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:31:10 by gbaud             #+#    #+#             */
/*   Updated: 2020/09/16 15:48:20 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>

int	ft_free_strs_tab(char **tab)
{
	int len;

	len = 0;
	while (tab[len])
		free(tab[len++]);
	free(tab[len]);
	free(tab);
	return (1);
}
