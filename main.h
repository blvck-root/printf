#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct cformat - basic structure of a format processor
 *
 * @type: char that signifies the type of arg to be printed
 * @f: pointer to function that prints arg
 * Description: structure of an object that converts a format
 * specifier to the corresponding argument
 */
typedef struct cformat
{
	char *type;
	int (*f)(va_list, char *, int);
} cf_t;

int _printf(const char *format, ...);

#endif
