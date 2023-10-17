#include "main.h"

/**
 * handle_c - add char to buffer
 * @arg: list of variable args pointing to current arg
 * @buffer: output builder string
 * @index: where to start adding char
 * Return: number of characters added to buffer
 */
int pc(va_list arg, char *buffer, int index)
{
	char c = va_arg(arg, int); /* char promoted to int */
	buffer[index] = c;
	return (1);
}
