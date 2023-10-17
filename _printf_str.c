#include "main.h"

/**
 * ps - print string
 * @arg: list of variable args pointing to current arg
 * Return: number of printed chars
 */
int ps(va_list arg)
{
	int printed = 0;
	char *s = va_arg(arg, char *);

	if (s == NULL)
		return (-1);

	/* s is an empty string */
	if (s[0] == '\0')
		return (printed);

	while (*s != '\0')
	{
		_putchar(*s++);
		++printed;
	}
	return (printed);
}
