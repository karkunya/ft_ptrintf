#include "ft_printf_bonus.h"

static int	ft_numlen(unsigned long int x)
{
	int	ret;

	ret = 0;
	if (x == 0)
		return (1);
	while (x > 0 && ++ret)
		x = x / 16;
	return (ret);
}

static int	apply_flags2(t_flags *flags, int ret, char *s_x)
{
	flags->dot = flags->dot - ret + 2;
	if (flags->dot < 0)
		flags->dot = 0;
	flags->width = flags->width - (flags->dot + ret);
	write(1, "0x", 2);
	while (flags->dot-- > 0 && ++ret)
		write(1, "0", 1);
	write(1, s_x, ft_strlen(s_x));
	while (flags->width-- > 0 && ++ret)
		write(1, " ", 1);
	return (ret);
}

static int	apply_flags3(t_flags *flags, int ret, char *s_x, char ind)
{
	flags->dot = flags->dot - ret + 2;
	if (flags->dot < 0)
		flags->dot = 0;
	flags->width = flags->width - (flags->dot + ret);
	while (flags->width-- > 0 && ++ret)
		write(1, &ind, 1);
	write(1, "0x", 2);
	while (flags->dot-- > 0 && ++ret)
		write(1, "0", 1);
	write(1, s_x, ft_strlen(s_x));
	return (ret);
}

static int	apply_flags(t_flags *flags, unsigned long int x, char *s_x)
{
	int		ret;
	char	ind;

	ret = ft_numlen(x) + 2;
	ind = ' ';
	if (flags->zero && flags->dot == -1)
		ind = '0';
	if (flags->dot == 0 && x == 0)
	{
		if (flags->minus)
			write(1, "0x", 2);
		while (flags->width-- > 2 && ++ret)
			write(1, &ind, 1);
		if (!(flags->minus))
			write(1, "0x", 2);
		return (ret - 1);
	}
	else if (flags->minus)
		ret = apply_flags2(flags, ret, s_x);
	else
		ret = apply_flags3(flags, ret, s_x, ind);
	return (ret);
}

int	treat_p(t_flags *flags)
{
	unsigned long int	x;
	int					ret;
	char				*s_x;

	x = va_arg(*(flags->argv), unsigned long int);
	if (x == 0)
		x = 0;
	s_x = ft_itoap(x);
	if (s_x == NULL)
		return (0);
	ret = apply_flags(flags, x, s_x);
	free(s_x);
	(*flags->format)++;
	return (ret);
}
