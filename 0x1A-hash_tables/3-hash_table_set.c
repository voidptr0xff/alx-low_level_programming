#include "hash_tables.h"
/**
 * hash_table_set - inserts an element into the hash table.
 *
 *@ht: hash table to insert or update.
 *
 *@key: key associated with a value.
 *
 *@value: value associated with key.
 *
 *Return: Always 1 if success or 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *temp;
	hash_node_t *Node = malloc(sizeof(hash_node_t));
	hash_node_t *head_ptr = malloc(sizeof(hash_node_t));

	if (!ht)
		return (0);
	if (!Node)
		return (0);
	Node->key = (char *) malloc(strlen(key) + 1);
	Node->value = (char *) malloc(strlen(value) + 1);

	strcpy(Node->key, key);
	strcpy(Node->value, value);
	index = key_index((const unsigned char *)key, ht->size);
	if (ht->array[index])
	{
		if (strcmp(ht->array[index]->key, Node->key))
		{
			if (head_ptr)
			{
				printf("..hello\n");
				temp = head_ptr;
				while (temp->next)
					temp = temp->next;
				temp->next = Node;
				Node->next = NULL;
			}
			strcpy(Node->value, value);
			head_ptr = Node;
			Node->next = NULL;
		}
		strcpy(ht->array[index]->value, value);
		return (1);
	}
	ht->array[index] = Node;
	return (1);
}
