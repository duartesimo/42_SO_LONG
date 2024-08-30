#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[i])
	{
		ft_putchar((int)str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long nbr, char *base)
{
	int	count;
	int	len;

	len = 0;
	while (base[len])
		len++;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= len)
	{
		count += ft_putnbr(nbr / len, base);
	}
	count += ft_putchar(base[nbr % len]);
	return (count);
}

int	ft_putptr(unsigned long long ptr)
{
	int					count;
	unsigned long long	len;
	char				*base;

	count = 0;
	len = 16;
	base = "0123456789abcdef";
	if (!ptr)
		return (write (1, "(nil)", 5));
	count += write (1, "0x", 2);
	if (ptr >= len)
	{
		count += ft_putnbr(ptr / len, base);
	}
	count += ft_putchar(base[ptr % len]);
	return (count);
}
