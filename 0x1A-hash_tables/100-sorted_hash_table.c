#include "hash_tables.h"

/**
 * add_node_to_sorted_list - Adds a node to the sorted linked list.
 * @ht: The sorted hash table.
 * @new: The new node to add.
 */
void add_node_to_sorted_list(shash_table_t *ht, shash_node_t *new)
{
	shash_node_t *tmp;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, new->key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, new->key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}
}

/**
 * create_and_add_node - Creates a new node and adds it to the hash table.
 * @ht: The sorted hash table.
 * @key: The key to add - It cannot be an empty string.
 * @value: The value associated with key.
 * Return: The newly created node.
 */
shash_node_t *create_and_add_node(shash_table_t *ht,
		const char *key, const char *value)
{
	shash_node_t *new;
	char *value_copy;
	unsigned long int index;

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(value_copy);
		return (NULL);
	}

	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(value_copy);
		free(new);
		return (NULL);
	}

	new->value = value_copy;
	new->

