#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*res;
	int		i;
	char	ss;

	ss = (char)c;
	i = 0;
	res = (char *)s;
	while (n--)
	{
		if (res[i] == ss)
			return (res);
		res++;
	}
	return (0);
}
