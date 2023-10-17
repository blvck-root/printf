#include "main.h"

/**
 * ps - add string to buffer
 * @arg: list of variable args pointing to current arg
 * @buffer: output builder string
 * @index: where to start adding string
 * Return: number of characters added to buffer
 */
int ps(va_list arg, char *buffer, int index)
{
	int i = 0, new_size;
	char *s = va_arg(arg, char *);

	if (s == NULL)
		return (-1);

	new_size = strlen(buffer) + strlen(s);

	/* s is an empty string */
	if (s[0] == '\0')
		return (i);

	buffer = realloc(buffer, new_size * sizeof(char));

	if (buffer == NULL)
		return (-1);

	while (*s != '\0')
	{
		buffer[index + i] = *s++;
		i++;
	}
	return (i);
}
