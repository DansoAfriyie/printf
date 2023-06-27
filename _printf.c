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
	char *buffer;
	int i;


	buffer = malloc(sizeof(char) * (1000));

	for (i = 0; i < 10 ; i++)
	{
		if (*(format + i) != '%')
		{
			_write(format);
		}
		else if (*(format + i) == 'c')
		{
			_write(va_arg(ap, const char *));
		}
		/*
		else if (*(format + i) == 's')
		{
			buffer = va_arg(ap, const char *);
			for (i = 0; *(buffer + i) != '\0'; i++)
			{
				_write(*buffer);
			}
		}
		*/
	}
	/* print up to the character before % */
	for ( ; *format == '%'; format++)
	{
		_write(format);
		format++;
	}

	va_start(ap, format);

	va_end(ap);
	return (sizeof(buffer));
	free(buffer);
}
