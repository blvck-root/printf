#include "main.h"

/**
 * pi - print decimals
 * @args: argument list
 * Return: number of digits and symbols in decimal
 */

int pi(va_list args)
{
	int n, num, ld, dig, exp, i, val = 1;

	n = va_arg(args, int);
	if (n < 0)
		val = -1;
	ld = n % 10;
	i = 1;
	exp = 1;
	n = n / 10;
	num = n;
	if (val < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		ld = -ld;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig  + '0');
			num -= dig * exp;
			exp = exp / 10;
			i++;
		}
	}
	_putchar(ld + '0');
	return (i);
}
