#include<stdio.h>

#include "chain_utils.h"
#include "hash_table_utils.h"

void ht_print(HashTable* ht) {
    printf("{");
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        if (!chain_empty(ht->table + i)) {
            chain_print(ht->table + i);
            if (i < TABLE_SIZE - 1 && !chain_empty(ht->table + i + 1)) {
                printf(",");
            }
        } 
    }
    printf("}\n");
}

