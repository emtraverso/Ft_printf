/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_X.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:47:02 by etravers          #+#    #+#             */
/*   Updated: 2022/10/21 17:47:04 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

void	ft_putnbr_xup(uintptr_t nbr, int fd, int *count)
{	
	if (nbr >= 16)
	{
		ft_putnbr_xup(nbr / 16, fd, count);
		ft_putnbr_xup(nbr % 16, fd, count);
	}
	else
		ft_putchar_fd("0123456789ABCDEF"[nbr], fd, count);
}
