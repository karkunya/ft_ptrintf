#include "ft_printf_bonus.h"

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

static int	apply_flags(t_flags *flags, char *s)
{
	int		ret;
	char	ind;
	int		len;

	ret = 0;
	ind = ' ';
	len = (int)ft_strlen(s);
	if ((flags->dot) != -1)
		len = ft_min((flags->dot), len);
	if ((flags->zero) != 0)
		ind = '0';
	if (flags->minus)
		write(1, s, len);
	flags->width = (flags->width) - (len - 1);
	if (flags->width)
		while (((flags->width)-- > 1) && ++ret)
			write(1, &ind, 1);
	if (!(flags->minus))
		write(1, s, len);
	ret += len;
	return (ret);
}

int	treat_s(t_flags *flags)
{
	char	*s;
	int		ret;

	s = va_arg(*(flags->argv), char *);
	if (s == NULL)
		s = "(null)";
	ret = apply_flags(flags, s);
	(*flags->format)++;
	return (ret);
}
