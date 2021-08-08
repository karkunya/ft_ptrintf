#include "ft_printf_bonus.h"

static int	apply_flags2(t_flags *flags, char *s_num, int d, char ind)
{
	int	ret;
	int	sign;
	int	dot1;

	ret = 0;
	dot1 = (flags->dot == 0);
	sign = (d < 0);
	flags->dot = flags->dot - (ft_strlen(s_num));
	if (flags->dot < 0)
		flags->dot = 0;
	flags->width = flags->width - (flags->dot + (ft_strlen(s_num) - 1) + sign);
	if (!(flags->minus))
		while (flags->width-- > 1 && ++ret)
			write(1, &ind, 1);
	if (sign)
		write(1, "-", 1);
	while (flags->dot-- > 0 && ++ret)
		write(1, "0", 1);
	if (!dot1 || d != 0)
		write(1, s_num, ft_strlen(s_num));
	if (flags->minus)
		while (flags->width-- > 1 && ++ret)
			write(1, &ind, 1);
	return (ret);
}

static int	apply_flags3(t_flags *flags, char *s_num, int d, char ind)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = (d < 0);
	flags->width = flags->width - ((ft_strlen(s_num) - 1) + sign);
	if (sign && ind == '0')
		write(1, "-", 1);
	if (!(flags->minus))
		while (flags->width-- > 1 && ++ret)
			write(1, &ind, 1);
	if (sign && ind == ' ')
		write(1, "-", 1);
	write(1, s_num, ft_strlen(s_num));
	if (flags->minus)
		while (flags->width-- > 1 && ++ret)
			write(1, &ind, 1);
	return (ret);
}

static int	apply_flags(t_flags *flags, int d, char *s_num)
{
	int		ret;
	int		sign;
	char	ind;

	sign = (d < 0);
	ret = ft_strlen(s_num) + sign;
	ind = ' ';
	if (flags->zero && flags->dot == -1)
		ind = '0';
	if (flags->dot == 0 && d == 0)
	{
		while (flags->width-- > 0 && ++ret)
			write(1, &ind, 1);
        free(s_num);
		return (ret - 1);
	}
	else if (flags->dot != -1)
		ret += apply_flags2(flags, s_num, d, ind);
	else
		ret += apply_flags3(flags, s_num, d, ind);
	free(s_num);
	return (ret);
}

int	treat_digit(t_flags *flags)
{
	int		d;
	int		ret;
	char	*s_num;

	d = va_arg(*(flags->argv), int);
	s_num = ft_itoa_base(d);
	if (s_num == NULL)
		return (0);
	ret = apply_flags(flags, d, s_num);
	(*flags->format)++;
	return (ret);
}
