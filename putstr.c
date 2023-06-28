#include "main.h"

/**
 * putstr - print strings
 * @str: String to print
 *
 * Return: Void
 */
void putstr(const char *str)
{
	while (*str)
	{
		_write(*str);
		str;
	}
}
