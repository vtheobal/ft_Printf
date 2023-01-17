#include "ft_printf.h"

int	ft_ulength(unsigned int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa (unsigned int i)
{
	int		len;
	char	*result;

	len = ft_ulength(i);
	result = (char *) malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (!i)
		result[0] = '0';
	result[len] = 0;
	while (i)
	{
		len--;
		result[len] = i % 10 + '0';
		i /= 10;
	}
	return (result);
}
