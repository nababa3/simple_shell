#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int convert_string_to_integer(char *str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (i = 0;  str[i] != '\0'; i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error_message - prints an error message
 * @info: the parameter & return info struct
 * @error_string: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error_message(info_t *info, char *error_string)
{
	print_error_string(info->filename);
	print_error_string(": ");
	print_decimal(info->line_count, STDERR_FILENO);
	print_error_string(": ");
	print_error_string(info->argv[0]);
	print_error_string(": ");
	print_error_string(error_string);
}

/**
 * print_decimal - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_decimal(int input, int fd)
{
	int (*print_character)(char) = print_character;
	int i, count = 0;
	unsigned int absolute_value, current;

	if (fd == STDERR_FILENO)
		print_character = print_error_character;
	if (input < 0)
	{
		absolute_value = -input;
		print_character('-');
		count++;
	}
	else
		absolute_value = input;
	current = absolute_value;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absolute_value / i)
		{
			print_character('0' + current / i);
			count++;
		}
		current %= i;
	}
	print_character('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buffer: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buffer)
{
	int
			for (int i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}

