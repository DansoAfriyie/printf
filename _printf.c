#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
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
	const char *buffer;
	int i;


	va_start(ap, format);

	while (format)
	{
		if (*format != '%')
		{
			_write(format);
		}
		else if (*format == 'c')
		{
			_write(va_arg(ap, char *));
		}

		else if (*format == 's')
		{
			buffer = va_arg(ap, const char *);
			for (i = 0; *(buffer + i) != '\0'; i++)
			{
				_write(buffer);
			}
		}
		format++;
	}

	va_end(ap);
	return (sizeof(buffer));
}
