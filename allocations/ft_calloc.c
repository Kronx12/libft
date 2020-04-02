/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.le-101.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:29:03 by gbaud             #+#    #+#             */
/*   Updated: 2020/03/01 12:27:07 by gbaud            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allowed;
	size_t	i;

	i = size * nmemb;
	if (!(allowed = malloc(i)))
		return (NULL);
	ft_bzero(allowed, i);
	return (allowed);
}
