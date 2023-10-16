#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * handle_c - add char to buffer
 * @arg: list of variable args pointing to current arg
 * @buffer: output builder string
 * @index: where to start adding char
 * Return: number of characters added to buffer
 */
int handle_c(va_list arg, char *buffer, int index)
{
	char c = va_arg(arg, int); /* char promoted to int */

	printf("%c\n", c);
	buffer[index] = c;
	return (1);
}

/**
 * handle_s - add string to buffer
 * @arg: list of variable args pointing to current arg
 * @buffer: output builder string
 * @index: where to start adding string
 * Return: void
 */
int handle_s(va_list arg, char *buffer, int index)
{
	int i = 0;
	char *s = va_arg(arg, char *);

	while (*s != '\0')
	{
		buffer[index + i] = *s++;
		i++;
	}
	return (i);
}

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
	int j = 0;
	cf_t print[] = { {"c", handle_c}, {"s", handle_s}, {NULL, NULL} };

	if (type == '%')
	{
		buffer[i] = '%';
		return (++i);
	}

	while (print[j].type)
	{
		if (print[j].type[0] == type)
		{
			i += print[j].f(arg, buffer, i);
			return (i);
		}
		j++;
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
	int i = 0;

	if (format)
	{
		va_list ap;
		char *buf = malloc(strlen(format) * sizeof(char));

		if (buf == NULL)
			return (-1);

		va_start(ap, format);
		while (*format != '\0')
		{
			if (*format == '%')
			{
				i = handle_arg(*++format, buf, ap, i);
			}
			else
			{
				buf[i++] = *format;
			}
			format++;
		}
		va_end(ap);
		write(1, buf, strlen(buf));
	}
	return (i);
}
