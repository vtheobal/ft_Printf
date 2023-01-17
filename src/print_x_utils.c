#include "ft_printf.h"

int	ft_xlength(unsigned int n)
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

char	*ft_xitoa(unsigned int i, t_stack *stack)
{
	int		len;
	char	*result;

	len = ft_xlength(i);
	result = (char *) malloc(len + 1);
	if (result == NULL)
		return (NULL);
	if (!i)
		result[0] = '0';
	result[len] = 0;
	while (i)
	{
		len--;
		if (stack->conversion == 'x')
			result[len] = HEXADECIMAL_LOWERCASE[i % 16];
		else
			result[len] = HEXADECIMAL_UPPERCASE[i % 16];
		i /= 16;
	}
	return (result);
}
