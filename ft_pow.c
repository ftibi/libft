#include "libft.h"

int		ft_pow(int x, int n)
{
	if (n == 0)
		return (x);
	return (x * ft_pow(x, n - 1));
}
