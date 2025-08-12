#pragma once

#include <stdint.h>

#include "chain.h"

// m is chosen to be a 8-bit word (uint8_t)
#define TABLE_SIZE UINT8_MAX + 1


typedef struct HashTable {
    Chain table[TABLE_SIZE];
    uint32_t rnd_hash_param;
} HashTable;


uint8_t hash_key(uint32_t);
void ht_init(HashTable*);
void ht_insert(HashTable*, uint32_t, char*); 
void ht_delete(HashTable*, uint32_t);
void ht_locate(HashTable*, uint32_t);
void ht_free(HashTable*);

