#include "libft.h"

void	ft_putnbr_fd(int c, int fd)
{
	long int	n;

	n = c;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd((n / 10), fd);
	ft_putchar_fd(('0' + (n % 10)), fd);
}
