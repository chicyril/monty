#include "monty.h"

/**
 * is_digs - check if all characters in a string are digits
 * @str: the string
 *
 * Return: true or false
 */
bool is_digs(char *str)
{
	int i = 0;


	while (str[i])
		if (!isdigit(str[i++]))
			return (false);
	return (true);
}
