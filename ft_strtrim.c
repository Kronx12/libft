/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gbaud <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 04:14:04 by gbaud        #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 22:37:05 by gbaud       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (c == set[i])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	char	*r;
	char	*t;
	int		i;
	int		j;
	int		len;

	i = 0;
	t = (char *)s;
	len = ft_strlen(t);
	while (is_in_charset(set, t[i]))
		if (t[++i] == 0)
			return ((char *)ft_calloc(1, sizeof(char)));
	while (is_in_charset(set, t[len - 1]))
		len--;
	len = len - i;
	if (!(r = malloc((len + 1) * sizeof(char))))
		return (NULL);
	j = -1;
	while (j++ < len)
		r[j] = s[i + j];
	r[len] = '\0';
	return (r);
}
