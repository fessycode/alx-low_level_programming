#include "hash_tables.h"
/**
 * key_index - Assign index to a specific key
 * @key: Being the key
 * @size: Being the size of the hash table
 * Return: Hash value
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
