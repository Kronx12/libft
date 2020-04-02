/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 22:05:18 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 03:02:00 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*f;
	char	*s;
	size_t	i;

	i = 0;
	f = (char *)s1;
	s = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n && f[i] == s[i])
		i++;
	if (i == n)
		i--;
	return ((unsigned char)f[i] - (unsigned char)s[i]);
}
