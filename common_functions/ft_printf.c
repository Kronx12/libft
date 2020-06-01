/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaud <gbaud@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 04:22:21 by gbaud             #+#    #+#             */
/*   Updated: 2020/06/01 08:38:37 by gbaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_str	*char_to_str(char c)
{
	return (create_str(ft_ctos(c), 1));
}

t_str	*get_value(t_flags *f, va_list *lst)
{
	t_str	*str;
	char	*s;
	int		nbr;

	if (f->type == '%')
		str = char_to_str('%');
	else if (f->type == 'c')
		str = char_to_str(va_arg(*lst, int));
	else if (f->type == 's' && ((s = va_arg(*lst, char *)) || !s))
		str = create__str(ft_strdup(!(s) ? "(null)" : s));
	else if (f->type == 'p' && (str = create_str(ft_strdup("0x"), 2)))
	{
		s = ft_ulitoa_base(va_arg(*lst, intptr_t), "0123456789abcdef");
		str = ft_structfjoin(str, create_str(s, ft_strlen(s)), 2);
	}
	else if (f->type == 'd' || f->type == 'i')
		str = create__str(ftib(va_arg(*lst, int), "0123456789"));
	else if (f->type == 'u' && ((nbr = va_arg(*lst, int)) || !nbr))
		str = create__str(ftib(
			!(nbr >= 0) ? 4294967296 + nbr : nbr, "0123456789"));
	else if (f->type == 'x')
		str = create__str(ftib(va_arg(*lst, unsigned int), "0123456789abcdef"));
	else if (f->type == 'X')
		str = create__str(ftib(va_arg(*lst, unsigned int), "0123456789ABCDEF"));
	return (str);
}

t_str	*apply_flags(const char *str, int *i, va_list *lst)
{
	t_flags *f;
	t_str	*value;

	f = init_flags();
	fill_struct(str, i, lst, f);
	value = get_value(f, lst);
	flags_on_value(&value, f);
	free(f);
	return (value);
}

int		ft_printf(const char *str, ...)
{
	t_str	*buffer;
	int		i;
	va_list lst;

	va_start(lst, str);
	buffer = create_str(ft_strdup(""), 0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && ++i)
			buffer = ft_structfjoin(buffer, apply_flags(str, &i, &lst), 2);
		else
			buffer = ft_structfjoin(buffer, char_to_str(str[i]), 2);
		if (!buffer)
			return (-1);
		i++;
	}
	va_end(lst);
	ft_putnstr(buffer->str, buffer->len);
	i = buffer->len;
	free_str(buffer);
	return (i);
}
