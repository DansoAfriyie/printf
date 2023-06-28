#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

#pragma once

#define PRINTF_STATE_NORMAL		0
#define PRINTF_STATE_LENGTH		1
#define PRINTF_STATE_LENGTH_SHORT	2
#define PRINTF_STATE_LENGTH_LONG	3
#define PRINTF_STATE_SPECIFIER		4


#define PRINTF_LENGTH_DEFAULT		0
#define PRINTF_LENGTH_SHORT_SHORT	1
#define PRINTF_LENGTH_SHORT		2
#define PRINTF_LENGTH_LONG		3
#define PRINTF_LENGTH_LONG_LONG 	4


/**
 * _printf - produces output according to a format
 * @format: A character string to print
 *
 * Return: Number of characters written to stdout
 */
int _printf(const char *format, ...)
{
	int *argp = (int *)&format;
	int state = PRINTF_STATE_NORMAL;
	int length = 

	*argp++;
	while (*format)
	{
		switch (state)
		{
			case PRINTF_STATE_NORMAL:
				switch (*format)
				{
					case '%':
						state = PRINTF_STATE_LENGTH;
						break;
					default:
						putc(*format);
						break;
				}
				break;

			case PRINTF_STATE_LENGTH:
				switch (*format)
				{
					case 'h':
						length = PRINTF_LENGTH_SHORT;
						state = PRINTF_STATE_LENGTH_SHORT;
						break;
					case 'l':
						length = PRINTF_LENGTH_LONG;
						state = PRINTF_STATE_LENGTH_LONG;
						break;

					default:
						goto PRINTF_STATE_SPECIFIER;
						break;

				}
				break;

			case PRINTF_STATE_LENGTH_SHORT:
				if (*format == 'h')
				{
					length = PRINTF_STATE_SHORT_SHORT;
					state = PRINTF_STATE_SPECIFIER;
				}
				else goto PRINTF_STATE_SPECIFIER;
				break;

			case PRINTF_STATE_LENGTH_LONG:
				if (*format == 'l')
				{
					length = PRINTF_STATE_LONG_LONG;
					state = PRINTF_STATE_SPECIFIER;
				}
			
			else goto PRINTF_STATE_SPECIFIER;
			break;

			case PRINTF_STATE_SPECIFIER:
			PRINTF_STATE_SPECIFIER;
			switch (*format)
			{
				case 'c':
					putc((char)*argp);
					argp++;
					break;

				case 's':
					putstr(*(char**)argo);
					argp++;
					break;

				case '%':
					putc('%');
					break;
					
					
			}

		}

		format++;
	}
}
