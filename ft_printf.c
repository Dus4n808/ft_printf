/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:58:25 by dufama            #+#    #+#             */
/*   Updated: 2025/10/07 17:09:33 by dufama           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_args(va_list *args, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar_printf(va_arg(*args, int));
	else if (c == 's')
		i = ft_putstr_printf(va_arg(*args, char *));
	else if (c == 'd')
		i = ft_putnbr_printf(va_arg(*args, int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		res;
	va_list	args;

	va_start(args, str);
	res = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			if (*(str + 1) != '\0')
			{
				str++;
				res += ft_check_args(&args, *str);
			}
		}
		else
			res += ft_putchar_printf(*str);
		str++;
	}
	va_end(args);
	return (res);
}
