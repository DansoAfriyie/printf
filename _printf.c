#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: A character string
 *
 * Return: Number of characters written to stdout
 */
int _printf(const char *format, ...)
{
	va_list ap;
	const char *p, *sval;

	va_start(ap, format);

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

			default:
				_putchar(*p);
				break;
		}
	}
	va_end(ap);
	return (p - format);
}
