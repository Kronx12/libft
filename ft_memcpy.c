/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:04:21 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 23:15:48 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char		*s;
	unsigned char			*d;
	size_t					i;

	i = 0;
	if (!(dest) && !(src))
		return (NULL);
	s = (unsigned const char*)src;
	d = (unsigned char *)dest;
	while (n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
