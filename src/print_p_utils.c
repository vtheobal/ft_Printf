#include "ft_printf.h"

int	ft_plength(unsigned long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_pitoa(unsigned long i)
{
	int		len;
	char	*result;

	len = ft_plength(i);
	result = (char *) malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (!i)
		result[0] = '0';
	result[len] = 0;
	while (i)
	{
		len--;
		result[len] = HEXADECIMAL_LOWERCASE[i % 16];
		i /= 16;
	}
	return (result);
}
