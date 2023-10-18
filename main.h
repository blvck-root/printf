#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER(name, size) \
	const int buf_size = size; \
	char name[buf_size];

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
	int (*f)(va_list);
} cf_t;

void _putchar(char c);
int _printf(const char *format, ...);
int pc(va_list args);
int ps(va_list args);
int pi(va_list args);

#endif
