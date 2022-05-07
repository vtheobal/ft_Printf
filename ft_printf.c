#include "ft_printf.h"

static void	free_stack(t_stack *stack)
{
	stack->minus = 0;
	stack->zero = 0;
	stack->width = 0;
	stack->precision = 0;
	stack->conversion = 0;
	stack->dot = 0;
}

static void	print(t_stack *stack, va_list *args)
{
	if (stack->conversion == 'c')
		print_c(va_arg(*args, int), stack);
	else if (stack->conversion == 'i' || stack->conversion == 'd')
		print_i(va_arg(*args, int), stack);
	else if (stack->conversion == 's')
		print_s(va_arg(*args, char *), stack);
	else if (stack->conversion == 'u')
		print_u(va_arg(*args, unsigned int), stack);
	else if (stack->conversion == 'x' || stack->conversion == 'X')
		print_x(va_arg(*args, unsigned int), stack);
	else if (stack->conversion == 'p')
		print_p((unsigned long)va_arg(*args, void *), stack);
	else if (stack->conversion == '%')
		print_c('%', stack);
}

static void	handle_pars_two(const char **format, va_list *args, t_stack *stack)
{
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		stack->dot = 1;
		(*format)++;
		if (ft_isdigit(**format))
			stack->precision = ft_atoi(*format);
		else if (**format == '*')
		{
			stack->precision = va_arg (*args, int);
			(*format)++;
		}
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_strchr("cspdiuxX%", **format))
		stack->conversion = *(*format)++;
	if (stack->width < 0)
	{
		stack->width *= -1;
		stack->minus = 1;
	}
	if (stack->precision < 0)
		stack->dot = 0;
}

static void	handle_pars(const char **format, va_list *args, t_stack *stack)
{
	free_stack(stack);
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			stack->zero = 1;
		if (**format == '-')
			stack->minus = 1;
		(*format)++;
	}
	if (ft_isdigit(**format))
		stack->width = ft_atoi(*format);
	else if (**format == '*')
	{
		stack->width = va_arg(*args, int);
		(*format)++;
	}
	handle_pars_two(format, args, stack);
	print(stack, args);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_stack	stack;

	stack.error = 0;
	stack.symbols = 0;
	va_start (args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			handle_pars(&format, &args, &stack);
			if (stack.error)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			stack.symbols++;
		}
	}
	va_end(args);
	return (stack.symbols);
}
