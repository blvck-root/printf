#include "main.h"

/**
 * pc - print char
 * @arg: list of variable args pointing to current arg
 * Return: number of printed chars
 */
int pc(va_list arg)
{
	char c = va_arg(arg, int); /* char promoted to int */

	_putchar(c);
	return (1);
}
