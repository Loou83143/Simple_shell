#include "shell.h"

/**
 **_memset - occupies  memory with a constant byte
 *@s: points to the memory area
 *@b: Byte to fill *s with
 *@n: Number of bytes to be filled
 *Return: (s)  points to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;
	return (s);
}

/**
 * ffree - to  free a string of strings
 * @pp: The String of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - redisbutes a block of memory
 * @ptr: points to previous malloc'ated block
 * @old_size: the Byte size of previous block
 * @new_size: the Byte size of new block
 *
 * Return: points to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
