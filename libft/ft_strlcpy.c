#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ressize;
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	ressize = (ft_strlen(src));
	if (dstsize == 0)
		return (ressize);
	while ((i < dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ressize);
}
