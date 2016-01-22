#include "libft.h"

int		ft_pow(int x, int n)
{
	if (n == 0)
		return (1);
	return (x * ft_pow(x, n - 1));
}
