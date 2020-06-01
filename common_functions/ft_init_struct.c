/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 00:18:47 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:35 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	*create_str(char *s, int l)
{
	t_str *structure;

	if (!(structure = malloc(sizeof(t_str))) || !s)
		return (NULL);
	structure->str = s;
	structure->len = l;
	return (structure);
}

t_str	*create__str(char *s)
{
	return (create_str(s, ft_strlen(s)));
}

void	free_str(t_str *s)
{
	free(s->str);
	free(s);
}

t_flags	*init_flags(void)
{
	t_flags *f;

	if (!(f = malloc(sizeof(t_flags))))
		return (NULL);
	f->min = 0;
	f->flag = 0;
	f->width = 0;
	f->precision = -1;
	f->type = 0;
	f->result = NULL;
	return (f);
}

void	fill_struct(const char *str, int *i, va_list *lst, t_flags *f)
{
	fill_min(str, i, lst, f);
	fill_flags(str, i, f);
	fill_width(str, i, lst, f);
	fill_precision(str, i, lst, f);
	fill_type(str, i, lst, f);
}
