#include "hash_tables.h"
/**
 * hash_table_delete - To delete a hash table
 * @ht: Being the hash table to be deleted
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int n = 0;
	hash_node_t *next_node = NULL, *node = NULL;

	if (!ht)
		return;

	if (ht->array)
	{
		for (; n < ht->size; n++)
		{
			if (ht->array[n])
			{
				node = ht->array[n];
				while (node)
				{
					next_node = node->next;
					if (node->value)
						free(node->value);
					if (node->key)
						free(node->key);
					free(node);
					node = next_node;
				}
			}
		}
		free(ht->array);
	}
	free(ht);
}
