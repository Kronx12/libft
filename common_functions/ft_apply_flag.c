/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:22:21 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:44 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	*get_zero(int len)
{
	char *s;

	if (!(s = malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = 0;
	while (len--)
		s[len] = '0';
	return (create__str(s));
}

t_str	*get_space(int len)
{
	char *s;

	if (!(s = malloc(sizeof(char) * len + 1)))
		return (NULL);
	s[len] = 0;
	while (len--)
		s[len] = ' ';
	return (create__str(s));
}

int		except_on_value(t_str **s, char *str, int l)
{
	free((*s)->str);
	if (!((*s)->str = ft_strdup(str)))
		return (0);
	(*s)->len = l;
	return (1);
}

void	flags_on_value_2(t_str **str, t_flags *lst)
{
	if (lst->flag == '-' && lst->width > 0 && (lst->width - (*str)->len) > 0)
		(*str) = ft_structfjoin((*str), get_space(lst->width - (*str)->len), 2);
	else if (lst->flag == '0' && (*str)->len < lst->width)
	{
		if ((*str)->str[0] != '-')
			(*str) = ft_structfjoin(
				get_zero(lst->width - (*str)->len), (*str), 2);
		else
		{
			(*str) = ft_structfjoin(
				get_zero(lst->width - (*str)->len), (*str), 2);
			ft_replace((*str)->str, '-', '0');
		}
	}
	if ((*str)->len < lst->min)
		(*str) = ft_structfjoin(get_space(lst->min - (*str)->len), (*str), 2);
}

void	flags_on_value(t_str **s, t_flags *lst)
{
	if (((*s)->len - (ft_strchr_chr((*s)->str, '-') ? 1 : 0)) < lst->precision
		&& ft_strchr_chr("diuxX", lst->type))
	{
		(*s) = ft_structfjoin(get_zero(lst->precision - (*s)->len +
			(ft_strchr_chr((*s)->str, '-') ? 1 : 0)), (*s), 2);
		if (ft_strchr_chr((*s)->str, '-'))
			ft_replace((*s)->str, '-', '0');
	}
	else if ((*s)->len > lst->precision &&
		lst->precision > 0 && ft_strchr_chr("s", lst->type))
		(*s) = ft_strndup((*s), lst->precision, 1);
	else if (lst->precision == 0 && ft_strchr_chr("cspdiuxX", lst->type))
	{
		if (((*s)->str[0] == '0' || lst->type == 's') &&
			ft_strchr_chr("csdiuxX", lst->type))
			(*s) = (except_on_value(s, "", 0)) ? (*s) : NULL;
		else if (lst->type == 'p' && (*s)->str[2] == '0' && (*s)->str[3] == 0)
			(*s) = (except_on_value(s, "0x", 2)) ? (*s) : NULL;
	}
	if ((*s))
		flags_on_value_2(s, lst);
}
