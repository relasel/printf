/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 03:36:08 by deddara           #+#    #+#             */
/*   Updated: 2020/06/06 22:38:05 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void s_prec_handler_add(char *str, t_data *data_list)
{
	if (data_list->precision < ft_strlen(str))
	{
		while ((data_list->precision) && *str)
		{
			write(1, &*str, 1);
			data_list->precision--;
			str++;
		}
		return ;
	}
	while(*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

static void s_prec_handler(char *str, t_data *data_list)
{
	if (data_list->precision < ft_strlen(str))
	{
		while ((data_list->precision) && *str)
		{
			write(1, &*str, 1);
			data_list->len++;
			data_list->precision--;
			str++;
		}
		return ;
	}
	while(*str)
	{
		write(1, &*str, 1);
		data_list->len++;
		str++;
	}
}

static void	string_minus_handler(char *str, t_data *data_list)
{
	if (!(data_list->precision))
		return ;
	else if (data_list->precision)
		s_prec_handler(str, data_list);

}

static void string_simple_handler(char *str, t_data *data_list)
{
	if(data_list->precision < ft_strlen(str) && data_list->precision != -1)
		data_list->len += data_list->precision;
	else if (!(data_list->precision))
		data_list->len += 0;
	else
		data_list->len += ft_strlen(str);
	space_printer(data_list);
	s_prec_handler_add(str, data_list);
}

static void string_null_handler(t_data *data_list)
{
	if (data_list->flags & MINUS_FLAG)
	{
		string_minus_handler(data_list->null_str, data_list);
		space_printer(data_list);
		return ;
	}
	string_simple_handler(data_list->null_str, data_list);
	return ;
}

int	string_handler(t_data *data_list, va_list ***args)
{
	char *str;

	if(!(str = va_arg(***args, char *)))
	{
		string_null_handler(data_list);
		return (1);
	}
	if (data_list->flags & MINUS_FLAG)
	{
		string_minus_handler(str, data_list);
		space_printer(data_list);
		return (1);
	}
	string_simple_handler(str, data_list);
	return (1);
}
