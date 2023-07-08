#include "hash_tables.h"
/**
 * hash_table_print - Prints the entire contents of
 * the hash table.
 * @ht: Being the hash table
 * Return: Null
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int n = 0, last_pos = 0;
	hash_node_t *node = NULL;

	if (ht == NULL)
		return;
	putchar('{');
	if (ht)
	{
		for (; n < ht->size - 1; n++)
		{
			if (ht->array[n] != NULL)
				last_pos = n;
		}

		for (n = 0; n <= last_pos; n++)
		{
			node = ht->array[n];
			while (node)
			{
				printf("'%s': '%s'", node->key, node->value);
				node = node->next;
				if (n < last_pos - 1)
					printf(", ");
			}

		}
	}
	printf("}\n");
}
