#include "ft_printf.h"

static void	zero_width(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str);
	if (*str == '-' && stack->width > (int)ft_strlen(str))
	{
		*str = '0';
		stack->width--;
		stack->symbols++;
		ft_putchar_fd('-', 1);
	}
	while (stack->width > len)
	{
		stack->width--;
		ft_putchar_fd('0', 1);
		stack->symbols++;
	}
	ft_putstr_fd(str, 1);
	stack->symbols += len;
}

static void	minus_period(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str);
	if (*str == '-' && stack->precision > len - 1)
	{
		*str = '0';
		stack->symbols++;
		stack->width--;
		ft_putchar_fd('-', 1);
	}
	while (stack->precision > len)
	{
		len++;
		ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	while (len < stack->width)
	{
		len++;
		ft_putchar_fd(' ', 1);
	}
	stack->symbols += len;
}

static void	period(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str);
	if (*str == '-' && stack->precision > len - 1)
		stack->width--;
	while (stack->width > stack->precision && stack->width > len)
	{
		ft_putchar_fd(' ', 1);
		stack->width--;
		stack->symbols++;
	}
	if (*str == '-' && stack->precision > len - 1)
	{
		ft_putchar_fd('-', 1);
		*str = '0';
		stack->symbols++;
	}
	while (stack->precision > len)
	{
		len++;
		ft_putchar_fd('0', 1);
	}
	ft_putstr_fd(str, 1);
	stack->symbols += len;
}

static void	handle_i(char *str, t_stack *stack)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (stack->zero && !stack->dot && !stack->minus)
		zero_width(str, stack);
	else if (stack->minus && stack->dot)
		minus_period(str, stack);
	else if (stack->minus)
	{
		ft_putstr_fd(str, 1);
		while (stack->width > ++len)
			ft_putchar_fd(' ', 1);
		stack->symbols += len;
	}
	else if (stack->dot)
		period(str, stack);
	else
	{
		while (stack->width > ++len)
			ft_putchar_fd(' ', 1);
		ft_putstr_fd(str, 1);
		stack->symbols += len;
	}
}

void	print_i(int i, t_stack *stack)
{
	char	*str;

	if (!i && !stack->precision && stack->dot)
		str = ft_strdup ("\0");
	else
		str = ft_itoa (i);
	if (!str)
	{
		stack->error = -1;
		return ;
	}
	handle_i(str, stack);
	free(str);
}
