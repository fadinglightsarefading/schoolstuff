#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_putstr(char	*str)
{
	while (*str)
			write(1, str++, 1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	i;
	char	ch;

	va_start(ap, s);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '\\' && s[i + 1] == 'n')
		{
				write(1, "\n", 1);
				i++;
		}
		if (s[i] == '%' && s[i + 1] == 'c')
		{
				ch = (char)va_arg(ap, int);
				ft_putchar(ch);
				i++;
		}
		else if (s[i] == '%' && s[i + 1] == 's')
		{
				ft_putstr(va_arg(ap, char*));
				i++;
		}
/*		else if (s[i] == '%' && s[i + 1] == 'p')
		{
				ft_printhex(va_arg(ap, void*));
				i++;
		}
		else if (s[i] == % && s[i + 1] == d)
		else if (s[i] == % && s[i + 1] == i)
		else if (s[i] == % && s[i + 1] == u)
		else if (s[i] == % && s[i + 1] == x)
		else if (s[i] == % && s[i + 1] == X) */
		else if (s[i] == '%' && s[i + 1] == '%')
		{
				write(1, "%", 1);
				i++;
		}
		else
			ft_putchar(s[i]);
	}
	return (0);
}

int	main(void)
{
	ft_printf("This is a char: %c\nThis is a string: %s\n", 'A', "String.");
	return (0);
}
