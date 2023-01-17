#include "ft_printf.h"

static void	print_s1(char *str, t_stack *stack)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (stack->dot && stack->precision <= len - 1)
		len = stack->precision;
	while (i < len && stack->minus)
		ft_putchar_fd(str[i++], 1);
	while (stack->width > len)
	{
		ft_putchar_fd(' ', 1);
		stack->width--;
		stack->symbols++;
	}
	while (i < len && !stack->minus)
		ft_putchar_fd(str[i++], 1);
	stack->symbols += len;
}

void	print_s(char *str, t_stack *stack)
{
	if (str == NULL)
		str = "(null)";
	if (stack->precision < 0)
		stack->dot = 0;
	print_s1(str, stack);
}
