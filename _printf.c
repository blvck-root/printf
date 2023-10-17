#include "main.h"

/**
 * handle_arg - convert format specifier to argument
 * @type: format specifier
 * @buffer: output string
 * @arg: argument pointer
 * @i: format specifier's position in buffer
 * Return: index
 */
int handle_arg(char type, char *buffer, va_list arg, int i)
{
	int res, j = 0;
	cf_t print[] = { {"c", pc}, {"s", ps}, {NULL, NULL} };

	if (type == '%')
	{
		buffer[i] = '%';
		return (++i);
	}

	while (print[j].type)
	{
		if (print[j].type[0] == type)
		{
			/* if format conversion fails res = -1 */
			res = print[j].f(arg, buffer, i);
			i = res < 0 ? -1 : (i + res);
			return (i);
		}
		++j;
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
	int i = 0, j = 0, size = strlen(format) + 1;

	if (format && size > 0 && !(format[j] == '%' && format[j + 1] == '\0'))
	{
		va_list ap;
		char *buf = malloc(size * sizeof(char));

		if (buf == NULL)
			return (-1);

		va_start(ap, format);
		while (format[j] != '\0')
		{
			if (format[j] == '%')
			{
				i = handle_arg(format[++j], buf, ap, i);
				if (i < 0)
				{
					free(buf);
					buf = NULL;
					return (-1);
				}
			}
			else
			{
				buf[i++] = format[j];
			}
			++j;
		}
		va_end(ap);
		buf[i] = '\0';
		write(1, buf, i);

		free(buf);
		buf = NULL;
		return (i);
	}
	return (-1);
}
