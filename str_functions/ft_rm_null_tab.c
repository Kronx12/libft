/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rm_null_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 07:50:30 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/08 15:22:06 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		count_legit(char **tab)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (tab[++i])
		if (ft_strcmp(tab[i], ""))
			res++;
	return (res);
}

char	**ft_rm_null_tab(char **tab, t_boolean f)
{
	char	**res;
	int		i;
	int		j;

	if (!(res = ft_calloc(count_legit(tab) + 1, sizeof(char *))))
		return (NULL);
	i = -1;
	j = -1;
	while (tab[++i])
		if (ft_strcmp(tab[i], ""))
			res[++j] = ft_strdup(tab[i]);
	if (f == TRUE)
		ft_free_strs_tab(tab);
	return (res);
}
