#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft/libft.h"

int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *s);
int	ft_printf(const char *str, ...);
int	ft_check_args(va_list *args, char c);
int	ft_putnbr_printf(int nb);


#endif
