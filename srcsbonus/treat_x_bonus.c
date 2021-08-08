#include "ft_printf_bonus.h"

static int	apply_flags2(t_flags *flags, int ret, char *s_x)
{
	flags->dot = flags->dot - ret;
	if (flags->dot < 0)
		flags->dot = 0;
	flags->width = flags->width - (flags->dot + ret);
	while (flags->dot-- > 0 && ++ret)
		write(1, "0", 1);
	write(1, s_x, ft_strlen(s_x));
	while (flags->width-- > 0 && ++ret)
		write(1, " ", 1);
	return (ret);
}

static int	apply_flags3(t_flags *flags, int ret, char *s_x, char ind)
{
	flags->dot = flags->dot - ret;
	if (flags->dot < 0)
		flags->dot = 0;
	flags->width = flags->width - (flags->dot + ret);
	while (flags->width-- > 0 && ++ret)
		write(1, &ind, 1);
	while (flags->dot-- > 0 && ++ret)
		write(1, "0", 1);
	write(1, s_x, ft_strlen(s_x));
	return (ret);
}

static int	apply_flags(t_flags *flags, unsigned int x, char *s_x)
{
	int		ret;
	char	ind;

	ret = lenofnum(x, 16);
	ind = ' ';
	if (flags->zero && flags->dot == -1)
		ind = '0';
	if (flags->dot == 0 && x == 0)
	{
		while (flags->width-- > 0 && ++ret)
			write(1, &ind, 1);
		return (ret - 1);
	}
	else if (flags->minus)
	{
		ret = apply_flags2(flags, ret, s_x);
	}
	else
	{
		ret = apply_flags3(flags, ret, s_x, ind);
	}
	return (ret);
}

int	treat_x(t_flags *flags)
{
	unsigned int	x;
	int				ret;
	char			*s_x;

	x = va_arg(*(flags->argv), unsigned int);
	s_x = ft_itoa16(x, STR16);
	if (s_x == NULL)
		return (0);
	ret = apply_flags(flags, x, s_x);
	free(s_x);
	(*flags->format)++;
	return (ret);
}
