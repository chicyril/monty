#include "monty.h"

/**
 * isdelim - search for a character in a string of characters
 * @c: the character being searched for
 * @str: the string being searched
 *
 * Return: true if found, false otherwise
 **/
bool isdelim(char c, const char *str)
{
	int i = 0;


	while (str[i])
		if (c == str[i++])
			return (true);
	return (false);
}


/**
 * mv_ptr - move a pointer to a string, to the first occurrence of any
 * delimiter character in the string
 * @str: the string pointer
 * @delim: a string containing delimiters
 *
 * Return: pointer to the first occurrence of the delimiter in the string
 **/
char *mv_ptr(char *str, const char *delim)
{
	for (; *str; str++)
		if (isdelim(*str, delim))
			break;
	return (str);
}


/**
 * str_tok -  find tokens(words) in a string
 * @str: the string to tokenize
 * @delim: delimiters separating words in the string
 *
 * Return: a pointer to the token found after each calls or null
 **/
char *str_tok(char *str, const char *delim)
{
	static char *curr_pos;
	char *tok = NULL;


	if (delim)
	{
		if (str)
			curr_pos = str;
		if (curr_pos && *curr_pos)
		{
			while (*curr_pos && isdelim(*curr_pos, delim))
				curr_pos++;
			if (*curr_pos)
			{
				tok = curr_pos;
				curr_pos = mv_ptr(curr_pos, delim);
				if (*curr_pos)
				{
					curr_pos[0] = '\0';
					curr_pos++;
				}
				return (tok);
			}
		}
	}
	curr_pos = NULL;
	return (NULL);
}
