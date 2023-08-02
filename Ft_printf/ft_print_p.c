/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:48:12 by etravers          #+#    #+#             */
/*   Updated: 2022/10/19 16:48:13 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(uintptr_t nbr, int fd, int *count)
{
	if (!nbr)
		ft_putstr_fd("(nil)", fd, count);
	else
	{
		ft_putstr_fd("0x", fd, count);
		ft_putnbr_base_fd(nbr, fd, count);
	}
}
