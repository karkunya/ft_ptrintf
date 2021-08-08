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

char	*ft_itoap(unsigned long int x)
{
	char	*s_x;
	int		numlen;

	numlen = ft_numlen(x);
	s_x = malloc(sizeof(char) * (numlen + 1));
	if (s_x == 0)
		return (NULL);
	s_x[numlen] = '\0';
	while (numlen--)
	{
		s_x[numlen] = STR16[x % 16];
		x = x / 16;
	}
	return (s_x);
}
