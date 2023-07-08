#include "hash_tables.h"
/**
 * hash_table_create - To create a hash table of size ``size``
 * @size: Defines the size of the table
 * Return: NULL if failed or created table on success
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *h;
	unsigned long int n;

	h = malloc(sizeof(hash_table_t));
	if (h == NULL)
		return (NULL);
	h->array = malloc(sizeof(hash_node_t *) * size);
	/**
	 * NOTE TO SELF:
	 * why malloc for ``sizeof(hash_node_t *)``?
	 * ANS: ``array`` is an array of pointers, the initial
	 * ``sizeof(hash_node_t)`` allocates space for the
	 * typedef of hash_node_t (8 * 3 = 24 bytes) whereas
	 * ``sizeof(hash_node_t *)`` allocates space for
	 * pointer to hash_node_t (8 bytes).
	 */
	if (h->array == NULL)
	{
		free(h);
		return (NULL);
	}

	h->size = size;

	for (n = 0; n < h->size; n++)
	{
		h->array[n] = NULL;
	}

	return (h);
}
