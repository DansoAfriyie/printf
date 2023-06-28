#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: A character string to print
 *
 * Return: Number of characters written to stdout
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p, *sval;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p != '%')
		{
			_putchar(*p);
			continue;
		}
		switch (*++p)
		{
			case 'c':
				_putchar(va_arg(ap, int));
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					_putchar(*sval);
				break;
			case 'd':
				print_number(va_arg(ap, int));
				break;
			case 'i':
				print_number(va_arg(ap, int));
				break;
			default:
				_putchar(*p);
				break;
		}
	}
	va_end(ap);
	return (p - format);
}
