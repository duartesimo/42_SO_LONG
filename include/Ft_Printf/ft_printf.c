#include "ft_printf.h"

int	print_format(char special, va_list args)
{
	int	count;

	count = 0;
	if (special == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (special == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (special == 'd' || special == 'i')
		count += ft_putnbr((va_arg(args, int)), "0123456789");
	else if (special == 'u')
		count += ft_putnbr((va_arg(args, unsigned int)), "0123456789");
	else if (special == 'p')
	{
		count += ft_putptr(va_arg(args, unsigned long long));
	}
	else if (special == 'x')
		count += ft_putnbr((va_arg(args, unsigned int)), "0123456789abcdef");
	else if (special == 'X')
		count += ft_putnbr((va_arg(args, unsigned int)), "0123456789ABCDEF");
	else if (special == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	int			i;
	va_list		args;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += print_format(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}