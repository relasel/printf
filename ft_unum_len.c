/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unum_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:00:25 by deddara           #+#    #+#             */
/*   Updated: 2020/06/12 02:51:46 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional_funcs.h"

int	unum_len(unsigned int n)
{
	unsigned int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
