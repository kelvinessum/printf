#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	convert_match m[] = {
		{"%s", print_string}, {"%c", printf_charac},
		{"%%", printf_percent}
	};

	va_list args;
	long unsigned int i = 0, j;
	int len = 0;
	size_t m_size = sizeof(m) / sizeof(m[0]);

	va_start(args, format);

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		va_end(args);
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			for (j = 0; j < m_size; j++)
			{
				if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
				{
					len += m[j].f(args);
					i += 2;
					break;
				}
			}
			if (j == m_size)
			{
				_write('%');
				len++;
				i++;
			}
		}
		else {
			_write(format[i]);
			len++;
			i++;
		}
	}
	va_end(args);
	return len;
}
