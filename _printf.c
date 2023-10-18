#include "main.h"

/**
 * handle_arg - convert format specifier to argument
 * @type: format specifier
 * @args: argument pointer
 * Return: number of printed chars
 */
int handle_arg(char type, va_list args)
{
	int i = 0;
	cf_t print[] = { {"c", pc}, {"s", ps}, {"d", pi}, {"i", pi}, {NULL, NULL} };

	if (type == '%')
	{
		_putchar('%');
		return (1);
	}

	while (print[i].type)
	{
		if (print[i].type[0] == type)
		{
			return (print[i].f(args));
		}
		++i;
	}
	return (-1);
}

/**
 * _printf - prints output according to a specified format
 * @format: format string
 * Return: number of characters printed except '\0'
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int printed, printed_chars = 0, i = 0;

	/* throw error when format is NULL or "%" */
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			printed = handle_arg(format[++i], ap);
			if (printed < 0)
				return (-1);
			printed_chars += printed;
		}
		else
		{
			_putchar(format[i]);
			++printed_chars;
		}
		++i;
	}
	va_end(ap);
	return (printed_chars);
}
