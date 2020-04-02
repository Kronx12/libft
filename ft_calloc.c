/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calloc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:29:03 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 16:02:38 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

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
