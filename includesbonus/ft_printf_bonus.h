#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# define FLW_FLGS "-0.*"
# define FLW_TPS "cspdiuxX%"
# define STR16 "0123456789abcdef"
# define STR16UPPER "0123456789ABCDEF"

typedef struct s_flags
{
	int			dot;
	int			minus;
	int			star;
	int			width;
	int			type;
	int			zero;
	va_list		*argv;
	const char	**format;
}					t_flags;

typedef void (*t_flag_treatment_p)(t_flags*);

int			ft_printf(const char *format, ...);
void		treat_width(t_flags *flags);
int			treat_s(t_flags *flags);
int			treat_char(t_flags *flags);
int			treat_persent(t_flags *flags);
int			treat_digit(t_flags *flags);
int			treat_u(t_flags *flags);
int			treat_x(t_flags *flags);
int			treat_p(t_flags *flags);
int			treat_xupper(t_flags *flags);
int			emptyfunc(t_flags *flags);
void		ft_init_flags(va_list *argv, const char **format, t_flags *flags);
void		treat_zero(t_flags *flags);
void		treat_star(t_flags *flags);
void		treat_minus(t_flags *flags);
void		treat_dot(t_flags *flags);
char		*ft_itoa_base(int num);
char		*ft_itoa_base1(uintmax_t num);
char		*ft_itoa16(unsigned long int x, char *str);
char		*ft_itoap(unsigned long int x);
size_t		lenofnum(long long n, int delitel);

#endif
