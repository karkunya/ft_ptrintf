#include "libft.h"

int	ft_lstsize(t_list *current)
{
	int	i;

	if (!current)
		return (0);
	i = 1;
	while (current -> next != 0)
	{
		current = current -> next;
		i++;
	}
	return (i);
}
