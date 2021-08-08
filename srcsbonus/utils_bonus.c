#include "ft_printf_bonus.h"

size_t	lenofnum(long long n, int delitel)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n = n / delitel;
	}
	return (len);
}

char	*ft_itoa_base(int num)
{
	char		*result;
	size_t		len;
	long long	n;

	n = num;
	len = lenofnum(n, 10);
	if (n < 0)
		n = -n;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa_base1(uintmax_t num)
{
	char		*result;
	size_t		len;
	long long	n;

	n = num;
	len = lenofnum(n, 10);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}

char	*ft_itoa16(unsigned long int x, char *str)
{
	char	*s_x;
	int		numlen;

	numlen = lenofnum(x, 16);
	s_x = malloc(sizeof(char) * numlen + 1);
	if (s_x == 0)
		return (NULL);
	s_x[numlen] = '\0';
	while (numlen--)
	{
		s_x[numlen] = str[x % 16];
		x = x / 16;
	}
	return (s_x);
}

void	ft_init_flags(va_list *argv, const char **format, t_flags *flags)
{
	flags->dot = -1;
	flags->minus = 0;
	flags->star = 0;
	flags->width = 0;
	flags->type = 0;
	flags->zero = 0;
	flags->format = format;
	flags->argv = argv;
}
