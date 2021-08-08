#include "ft_printf_bonus.h"

void	treat_width(t_flags *flags)
{
	(flags->width) = ft_atoi(*(flags->format));
	while (ft_isdigit(**(flags->format)))
		(*flags->format)++;
}

void	treat_zero(t_flags *flags)
{
	if (!(flags->width) && !(flags->minus))
		(flags->zero) = 1;
	(*flags->format)++;
}

void	treat_star(t_flags *flags)
{
	(flags->width) = va_arg(*(flags->argv), int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
		flags->zero = 0;
	}
	(flags->star) = 1;
	(*flags->format)++;
}

void	treat_minus(t_flags *flags)
{
	(flags->minus) = 1;
	(flags->zero) = 0;
	(*flags->format)++;
}

void	treat_dot(t_flags *flags)
{
	(*flags->format)++;
	if (**(flags->format) == '*')
	{
		flags->dot = va_arg(*(flags->argv), int);
		(*flags->format)++;
	}
	else if (ft_isdigit(**(flags->format)))
	{
		flags->dot = ft_atoi(*(flags->format));
		(*flags->format)++;
	}
	else
		flags->dot = 0;
	while (ft_isdigit(**(flags->format)))
		(*flags->format)++;
	if (flags->dot < 0)
		flags->dot = -1;
}
