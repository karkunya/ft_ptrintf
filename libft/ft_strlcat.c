#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ressize;
	size_t	i;

	i = 0;
	ressize = (ft_strlen(dst));
	if (dstsize < ressize)
		return (dstsize + ft_strlen(src));
	while ((i < dstsize - ressize - 1) && src[i]
		&& (ressize < dstsize - 1) && (dstsize > 0))
	{
		dst[ressize + i] = src[i];
		i++;
	}
	dst[ressize + i] = '\0';
	return (ressize + ft_strlen(src));
}
