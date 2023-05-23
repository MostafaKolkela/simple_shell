#include "memory.h"
#include "text.h"
#include "commands.h"
#include "general.h"

/**
 * pattern_handler - Entr dhkb nfbv k mnfb ckx kk  bk
 * @info: input
 * @string: input
 * Return: string
**/

char *pattern_handler(general_t *info, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
	}

	return (string);
}

/**
 * analyze_patterns - Entry Pos kb kb jkbbvkjbkv
 * @info: input
 * @arguments: input
**/

void analyze_patterns(general_t *info, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * replace_value - dkjn dljn lnfnvlnnd l jdn
 * @info: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replace_value(general_t *info, int *index, char *string)
{
	int i, new_s, old_s;
	char *value;

	i = *index;
	i++;

	value = replacement(info, index, string + i);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = i;
	return (string);
}
