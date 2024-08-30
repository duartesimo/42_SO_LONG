#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(long nbr, char *base);
int	ft_putptr(unsigned long long ptr);
int	print_format(char special, va_list args);
int	ft_printf(const char *format, ...);

#endif
