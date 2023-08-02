/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:49:22 by etravers          #+#    #+#             */
/*   Updated: 2022/10/21 17:48:57 by etravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_check(const char **str, va_list args, int *count)
{
	char	*stringa;

	*str += 1;
	if (**str == 'c')
		ft_putchar_fd((char)va_arg(args, int), 1, count);
	else if (**str == 's')
	{
		stringa = va_arg(args, char *);
		ft_print_s(stringa, 1, count);
	}
	else if (**str == 'p')
		ft_print_p(va_arg(args, uintptr_t), 1, count);
	else if (**str == 'd' || **str == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (**str == 'u')
		ft_putnbru_fd(va_arg(args, unsigned int), 1, count);
	else if (**str == 'x')
		ft_putnbr_base_fd(va_arg(args, unsigned int), 1, count);
	else if (**str == 'X')
		ft_putnbr_xup(va_arg(args, unsigned int), 1, count);
	else if (**str == '%')
		ft_putchar_fd('%', 1, count);
	*str += 1;
	return (*count);
}

int	ft_printfinternal(const char *str, va_list args, int *count)
{
	while (*str)
	{
		if (*str == '%')
			ft_check(&str, args, count);
		else
		{
			ft_putchar_fd(*str, 1, count);
			str++;
		}
	}
	return (*count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	if (!str)
		return (0);
	ft_printfinternal(str, args, &count);
	va_end(args);
	return (count);
}
