#include "ft_printf.h"
typedef int (*t_treat_tips_p)(t_flags*);

void	init_flag_func_arr(t_flag_treatment_p flag_arr_func[128])
{
	unsigned char	c;

	c = '1';
	while (c <= '9')
		flag_arr_func[c++] = &treat_width;
	flag_arr_func['.'] = &treat_dot;
	flag_arr_func['-'] = &treat_minus;
	flag_arr_func['*'] = &treat_star;
	flag_arr_func['0'] = &treat_zero;
}

void	init_tips_func_arr(t_treat_tips_p flag_tips_arr[128])
{
	int	i;

	i = 0;
	while (i < 129)
		flag_tips_arr[i++] = &emptyfunc;
	flag_tips_arr['c'] = &treat_char;
	flag_tips_arr['%'] = &treat_persent;
	flag_tips_arr['s'] = &treat_s;
	flag_tips_arr['d'] = &treat_digit;
	flag_tips_arr['i'] = &treat_digit;
	flag_tips_arr['x'] = &treat_x;
	flag_tips_arr['X'] = &treat_xupper;
	flag_tips_arr['u'] = &treat_u;
	flag_tips_arr['p'] = &treat_p;
}

int	parsinput(const char **format, va_list *argv)
{
	int					result;
	t_flags				flags;
	t_flag_treatment_p	flag_arr_func[128];
	t_treat_tips_p		tips_func_arr[128];

	init_flag_func_arr(flag_arr_func);
	init_tips_func_arr(tips_func_arr);
	result = 0;
	(*format)++;
	ft_init_flags(argv, format, &flags);
	while ((ft_strrchr(FLW_FLGS, **format) || ft_isdigit(**format)) && **format)
		flag_arr_func[(unsigned char)**format](&flags);
	if (ft_strrchr(FLW_TPS, **format) && **format)
		result += tips_func_arr[(unsigned char)**format](&flags);
	return (result);
}

int	parse_format(va_list *argv, const char *format)
{
	int	result;

	result = 0;
	while (*format != 0)
	{
		if (*format == '%')
			result += parsinput(&format, argv);
		else
		{
			write(1, format, 1);
			result++;
			format++;
		}
	}
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	argv;
	int		ret;

	va_start(argv, format);
	ret = parse_format(&argv, format);
	va_end(argv);
	return (ret);
}
