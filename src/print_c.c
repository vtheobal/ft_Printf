#include "ft_printf.h"

void	print_c(char c, t_stack *stack)
{
	if (!stack->minus)
	{
		while (stack->width > 1)
		{
			ft_putchar_fd(' ', 1);
			stack->width--;
			stack->symbols++;
		}
		ft_putchar_fd(c, 1);
		stack->symbols++;
	}
	if (stack->minus)
	{
		ft_putchar_fd(c, 1);
		stack->symbols++;
		while (stack->width > 1)
		{
			ft_putchar_fd(' ', 1);
			stack->width--;
			stack->symbols++;
		}
	}
}
