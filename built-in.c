#include "shell.h"

/**
 * print_history - displays the history list, one command per line, preceded
 *                 with line numbers starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0
 */
int print_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - removes an alias from the alias list
 * @info: parameter struct
 * @str: the alias to unset
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *equal_sign_pos, temp;
	int ret;

	equal_sign_pos = _strchr(str, '=');
	if (!equal_sign_pos)
		return (1);
	temp = *equal_sign_pos;
	*equal_sign_pos = '\0';
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*equal_sign_pos = temp;
	return (ret);
}

/**
 * set_alias - sets an alias to a string
 * @info: parameter struct
 * @str: the string representing the alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *equal_sign_pos;

	equal_sign_pos = _strchr(str, '=');
	if (!equal_sign_pos)
		return (1);
	if (!*++equal_sign_pos)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *equal_sign_pos = NULL, *alias_string = NULL;

	if (node)
	{
		equal_sign_pos = _strchr(node->str, '=');
		for (alias_string = node->str; alias_string <= equal_sign_pos; alias_string++)
			_putchar(*alias_string);
		_putchar('\'');
		_puts(equal_sign_pos + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * handle_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *         constant function prototype.
 *
 * Return: Always 0
 */
int handle_alias(info_t *info)
{
	int i = 0;
	char *equal_sign_pos = NULL;
	list_t *alias_node = NULL;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			print_alias(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		equal_sign_pos = _strchr(info->argv[i], '=');
		if (equal_sign_pos)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

