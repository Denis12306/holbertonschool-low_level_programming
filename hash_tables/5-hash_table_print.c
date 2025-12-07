#include "hash_tables.h"
#include <stdio.h>
#include <string.h>
/**
 * hash_table_print - prints the contents of a hash table
 * @ht: hash table to print
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *node;
    int printed = 0; // indique si on a déjà imprimé un élément

    if (!ht)
        return;

    putchar('{');

    for (i = 0; i < ht->size; i++)
    {
        node = ht->array[i];
        while (node)
        {
            if (printed)
                printf(", "); // virgule avant chaque élément sauf le premier

            printf("'%s': '%s'", node->key, node->value);
            printed = 1;

            node = node->next;
        }
    }

    printf("}\n");
}
