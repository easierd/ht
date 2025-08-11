#include<stddef.h>

#include "hash_table.h"

uint8_t hash_key(uint32_t key) {
    return key % TABLE_SIZE;
}

void ht_init(HashTable* ht) {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        chain_init(ht->table + i);
    }
}

void ht_insert(HashTable* ht, uint32_t key, char* value) {
    uint8_t hash = hash_key(key);
    chain_prepend(ht->table + hash, key, value);
}


void ht_delete(HashTable* ht, uint32_t key) {
    uint8_t hash = hash_key(key);
    chain_remove(ht->table + hash, key);
}


void ht_free(HashTable* ht) {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        chain_free(ht->table + i);        
    }
}
