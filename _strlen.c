#include "main.h"

/**
 * _strlen - determine length of a string, excluding the null byte
 * @s: Character string
 *
 * Return: Number of characters of s
 */
int _strlen(char *s)
{
	char *p;

	p = s;
	while (*p != '\0')
		p++;

	return (p - s);
}
