#include <stdlib.h>

int	ft_isalpha(int chr)
{
	return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
}
