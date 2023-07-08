#include "hash_tables.h"
/**
 * hash_table_get - Gets value associated with a key
 * @ht: Being hash table
 * @key: Being the key to fetch
 * Return: Return value or NULL on exit failure
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index = 0;
	char *value = NULL;
	hash_node_t *node;

	if (!ht || !key)
		return (NULL);
	else if (strlen(key) == 0)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	if ((ht->array)[index] == NULL)
		return (NULL);

	node = ht->array[index];
	while (!value)
	{
		if (strcmp(node->key, key) == 0)
			value = node->value;
		node = node->next;
	}
	return (value);
}
