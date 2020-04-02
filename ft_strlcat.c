/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 14:17:52 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 15:12:53 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t size)
{
	size_t i;

	i = 0;
	while (size >= i && s[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t y;
	size_t src_size;
	size_t dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strnlen(dst, size);
	if (size > 1)
	{
		y = 0;
		i = dst_size;
		while (i <= size - 2 && src[y] != '\0')
		{
			dst[i] = src[y];
			dst[i + 1] = '\0';
			i++;
			y++;
		}
	}
	if (dst_size > size)
		dst_size = size;
	return (dst_size + src_size);
}
