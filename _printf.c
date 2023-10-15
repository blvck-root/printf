#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * error - print error
 * @message: error message as string
 * @code: error code as integer
 * Return: integer, exit status
 */
int error(char *message, int code)
{
	write(1, message, strlen(message));
	write(1, "\n", 1);
	exit(code);
}

/**
 * handle_c - add char to buffer
 * @buffer: output builder string
 * @index: where to start adding char
 * @c: char to be added to buffer
 * Return: void
 */
void handle_c(char *buffer, int index, char c)
{
	buffer[index] = c;
}

/**
 * handle_s - add string to buffer
 * @buffer: output builder string
 * @index: where to start adding string
 * @s: string to be added to buffer
 * Return: void
 */
void handle_s(char *buffer, int index, char *s)
{
	while (*s != '\0')
		buffer[index++] = *s++;
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
		char type, *s, *buffer = (char *)malloc(strlen(format) * sizeof(char));
		
		va_start(ap, format);
		if (buffer == NULL)
			error("Error: Memory allocation failed.", 98);
		while (*format != '\0')
		{
			if (*format == '%')
			{
				type = *++format;
				switch (type)
				{
					case 'c':
						/* char promoted to int */
						handle_c(buffer, i++, va_arg(ap, int));
						break;
					case 's':
						s = va_arg(ap, char *);
						handle_s(buffer, i, s);
						i += strlen(s);
						break;
					default:
						error("Error", 2);
				}
			}
			else
			{
				buffer[i++] = *format;
			}
			format++;
		}
		va_end(ap);
		write(1, buffer, strlen(buffer));
	}
	return(i);
}
