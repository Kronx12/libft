/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:01:39 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:43 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ftib(long long val, char *base)
{
	char			*str;
	int				res_len;
	unsigned int	base_len;
	long long		copy;

	base_len = ft_strlen(base);
	copy = (val < 0) ? val * -1 : val;
	res_len = (val < 0) ? 1 : 0;
	while (++res_len && copy >= base_len)
		copy /= base_len;
	if (!(str = malloc(res_len + 2)))
		return (NULL);
	str[0] = (val < 0) ? '-' : 0;
	val = (val < 0) ? val * -1 : val;
	str[res_len] = '\0';
	while (val >= base_len && --res_len)
	{
		str[res_len] = base[val % base_len];
		val /= base_len;
	}
	str[--res_len] = base[val];
	return (str);
}

t_str	*ft_structfjoin(t_str *s1, t_str *s2, int f)
{
	char	*r;
	char	*res;
	char	*sa;
	char	*sb;
	int		total;

	if (!s1 || !s2)
		return (NULL);
	total = s1->len + s2->len;
	sa = (char *)s1->str;
	sb = (char *)s2->str;
	if (!(r = malloc(sizeof(char) * (total + 1))))
		return (NULL);
	res = r;
	while (s1->len--)
		*r++ = *sa++;
	while (s2->len--)
		*r++ = *sb++;
	*r = '\0';
	if (f >= 1)
		free_str(s1);
	if (f > 1 || f == -1)
		free_str(s2);
	return (create_str(res, total));
}

t_str	*ft_strndup(t_str *str, int n, int f)
{
	char	*s;
	int		i;

	if (!(s = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = -1;
	while (++i < n)
		s[i] = str->str[i];
	s[i] = '\0';
	if (f == 1)
		free_str(str);
	return (create__str(s));
}

void	ft_putnstr(char *str, int len)
{
	while (len--)
		write(1, &(*str++), 1);
}
