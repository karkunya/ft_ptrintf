#include "ft_printf.h"

static int	apply_flags(t_flags *flags, char c)
{
	int		ret;
	char	ind;

	ret = 0;
	ind = ' ';
	if ((flags->zero) != 0)
		ind = '0';
	if (flags->minus)
		write(1, &c, 1);
	if (flags->width)
		while (((flags->width)-- > 1) && ++ret)
			write(1, &ind, 1);
	if (!(flags->minus))
		write(1, &c, 1);
	ret++;
	return (ret);
}

int	emptyfunc(t_flags *flags)
{
	if (flags->dot == -1)
		flags->dot = -1;
	(*flags->format)++;
	return ('2');
}

int	treat_char(t_flags *flags)
{
	char	c;
	int		ret;

	c = va_arg(*(flags->argv), int);
	ret = apply_flags(flags, c);
	(*flags->format)++;
	return (ret);
}
