#include "libft.h"

int		*ft_intnew(size_t size)
{
	return (ft_memalloc(sizeof(int) * (size + 1)));
}
