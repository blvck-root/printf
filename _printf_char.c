#include "main.h"

/**
 * pc - print char
 * @args: list of variable args pointing to current arg
 * Return: number of printed chars
 */
int pc(va_list args)
{
	char c = va_arg(args, int); /* char promoted to int */

	_putchar(c);
	return (1);
}
