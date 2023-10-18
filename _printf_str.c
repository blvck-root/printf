#include "main.h"

/**
 * ps - print string
 * @args: list of variable args pointing to current arg
 * Return: number of printed chars
 */
int ps(va_list args)
{
	int printed = 0;
	char *s = va_arg(args, char *);

	if (s == NULL)
		s = "(null)";

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
