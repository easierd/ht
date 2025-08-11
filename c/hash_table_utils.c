#include<stdio.h>
#include<stdbool.h>

#include "chain_utils.h"
#include "hash_table_utils.h"

void ht_print(HashTable* ht) {
    bool is_one_pair_printed = false;
    printf("{");
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        if (!chain_empty(ht->table + i)) {
            if (is_one_pair_printed) {
                printf(", ");
            }
            chain_print(ht->table + i);
            is_one_pair_printed = true;
        } 
    }
    printf("}\n");
}

