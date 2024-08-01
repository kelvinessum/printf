#include "main.h"

/**
 * printf_charac - prints a char.
 * @val: arguments.
 * Return: 1.
 */
int printf_charac(va_list args)
{
	char s;

	s = va_arg(args, int);
	_write(s);
	return (1);
}
