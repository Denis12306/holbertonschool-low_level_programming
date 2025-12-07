#include "hash_tables.h"
#include <string.h>
#include <stdlib.h>

/**
 * hash_table_set - A function that sets a key value pair in the hash table.
 * @ht: A pointer to hash table to set in.
 * @key: The key to set in hash table.
 * @value: The value to set as hash_node's value.
 * Return: 1 on success, or 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int index;
    char *key_dup, *value_dup;
    hash_node_t *new_node, *tmp;

    if (!ht || !key || !value || strlen(key) == 0)
        return (0);

    key_dup = strdup(key);
    value_dup = strdup(value);
    if (!key_dup || !value_dup)
    {
        free(key_dup);
        free(value_dup);
        return (0);
    }

    new_node = malloc(sizeof(hash_node_t));
    if (!new_node)
    {
        free(key_dup);
        free(value_dup);
        return (0);
    }

    new_node->key = key_dup;
    new_node->value = value_dup;
    new_node->next = NULL;

    index = key_index((const unsigned char *)key, ht->size);

    tmp = ht->array[index];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = value_dup;
            free(key_dup);
            free(new_node);
            return (1);
        }
        tmp = tmp->next;
    }

    new_node->next = ht->array[index];
    ht->array[index] = new_node;
    return (1);
}
