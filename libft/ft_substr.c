#include "libft.h"

static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*dst_start;
	size_t	raslen;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	raslen = min(len, ft_strlen(s) - start);
	dst = (char *)malloc(sizeof(char) * raslen + 1);
	if (!dst)
		return (0);
	dst_start = dst;
	dst[raslen] = '\0';
	while (s[start] && raslen--)
		*dst++ = s[start++];
	return (dst_start);
}
