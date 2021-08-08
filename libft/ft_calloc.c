#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	c = malloc(size * count);
	if (c == 0)
		return (0);
	ft_bzero(c, size * count);
	return (c);
}
