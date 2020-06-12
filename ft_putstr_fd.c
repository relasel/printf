/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 21:33:36 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 02:52:00 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	if (s[0] == 0)
		write(1, "0", 1);
	else
		write(1, s, ft_strlen(s));
}
