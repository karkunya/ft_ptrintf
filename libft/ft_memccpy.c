#include <stdlib.h>

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;

	dest_c = (unsigned char *)destination;
	src_c = (unsigned char *)source;
	while (n--)
	{
		*dest_c = *src_c++;
		if ((unsigned char)c == *dest_c++)
			return (destination + 1);
		destination++;
	}
	return (0);
}
