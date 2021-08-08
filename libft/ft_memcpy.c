#include <stdlib.h>

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char	*dest_c;
	char	*src_c;

	dest_c = (char *)destination;
	src_c = (char *)source;
	if (!destination && !source)
		return (0);
	while (n--)
		*dest_c++ = *src_c++;
	return (destination);
}
