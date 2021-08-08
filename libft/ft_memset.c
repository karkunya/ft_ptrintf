#include <stdlib.h>

void	*ft_memset(void *destination, int c, size_t n)
{
	char	*dest_c;

	dest_c = (char *)destination;
	while (n--)
		*dest_c++ = (char)c;
	return (destination);
}
