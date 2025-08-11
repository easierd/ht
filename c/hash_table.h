#pragma once

#include <stdint.h>

#include "chain.h"

#define TABLE_SIZE 37


typedef struct HashTable {
    Chain table[TABLE_SIZE];
} HashTable;


uint8_t hash_key(uint32_t);
void ht_init(HashTable*);
void ht_insert(HashTable*, uint32_t, char*); 
void ht_delete(HashTable*, uint32_t);
void ht_locate(HashTable*, uint32_t);
void ht_free(HashTable*);
