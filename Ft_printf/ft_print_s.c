/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:45:30 by etravers          #+#    #+#             */
/*   Updated: 2022/10/21 17:49:12 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_s(char *stringa, int fd, int *count)
{
	if (!stringa)
		ft_putstr_fd("(null)", fd, count);
	else
		ft_putstr_fd(stringa, fd, count);
}
