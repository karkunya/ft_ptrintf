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

int	treat_persent(t_flags *flags)
{
	char	c;
	int		ret;

	c = '%';
	ret = apply_flags(flags, c);
	(*flags->format)++;
	return (ret);
}
