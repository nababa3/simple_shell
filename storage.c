#include "shell.h"

/**
 * bfree - frees a pointer and NULL the address
 * @ppd: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ppd)
{
	if (ppd && *ppd)
	{
		free(*ppd);
		*ppd = NULL;
		return (1);
	}
	return (0);
}
