#include "ft_printf.h"

static void	minus_period(char *str, t_stack *stack, int len)
{
	while (stack->precision-- > len)
	{
		ft_putchar_fd('0', 1);
		stack->symbols++;
		stack->width--;
	}
	ft_putstr_fd("0x", 1);
	stack->symbols += 2;
	ft_putstr_fd(str, 1);
	stack->symbols += len;
	while (stack->width-- > len + 2)
	{
		ft_putchar_fd(' ', 1);
		stack->symbols++;
	}
}

static void	classic(char *str, t_stack *stack, int len)
{
	while (stack->width > stack->precision && stack->width-- > len + 2)
	{
		ft_putchar_fd(' ', 1);
		stack->symbols++;
	}
	while (stack->precision > len)
	{
		len++;
		ft_putchar_fd('0', 1);
	}
	ft_putstr_fd("0x", 1);
	stack->symbols += 2;
	ft_putstr_fd(str, 1);
	stack->symbols += len;
}

static void	zero_minus_period(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str);
	if (stack->zero && !stack->minus && !stack->dot)
	{
		while (stack->width-- > len)
		{
			ft_putchar_fd('0', 1);
			stack->symbols++;
		}
		ft_putstr_fd("0x", 1);
		stack->symbols += 2;
		ft_putstr_fd(str, 1);
		stack->symbols += len;
	}
	else
		minus_period(str, stack, len);
}

static void	period(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str);
	if (stack->minus)
	{
		ft_putstr_fd("0x", 1);
		stack->symbols += 2;
		ft_putstr_fd(str, 1);
		stack->symbols += len;
		while (stack->width-- > len + 2)
		{
			ft_putchar_fd(' ', 1);
			stack->symbols++;
		}
	}
	else
		classic(str, stack, len);
}

void	print_p(unsigned long n, t_stack *stack)
{
	char	*str;

	if (!n && !stack->precision && stack->dot)
	{
		str = malloc(1);
		*str = 0;
	}
	else
		str = ft_pitoa(n);
	if (!str)
		stack->error = -1;
	if (!str)
		return ;
	if ((stack->zero && !stack->dot && !stack->minus)
		|| (stack->dot && stack->minus))
		zero_minus_period(str, stack);
	else
		period(str, stack);
	free (str);
}
