#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<time.h>

#include "hash_table.h"

/*
 * efficient, but static and predictable
 */
uint8_t division_hash(uint32_t key) {
    return key % TABLE_SIZE;
}


/* 
 * if a is chosen randomly it's an efficient 
 * 2/m - universal hash functions generator
 */
uint8_t mul_shift_hash(uint32_t a, uint32_t key) {
    return (a * key) >> 24;
}


/*
 * return a random long
 * lrand48 is a stronger pseudorandom generator than 
 * rand()
 */
uint32_t get_rnd_param() {
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    srand48(time.tv_sec * 1000000000 + time.tv_nsec);
    return lrand48();

}


/* initialize all the chains in the hash table.
 * randomly pick a hash function
 */
void ht_init(HashTable* ht) {
    ht->rnd_hash_param = get_rnd_param();
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        chain_init(ht->table + i);
    }
}


void ht_insert(HashTable* ht, uint32_t key, char* value) {
    uint8_t hash = mul_shift_hash(ht->rnd_hash_param, key);
    char* located = chain_locate(ht->table + hash, key);
    if (!located) {
        chain_prepend(ht->table + hash, key, value);
    } else {
        fprintf(stderr, "Error table already contains key %u\n", key);
    }
}


char* ht_locate(HashTable* ht, uint32_t key) {
    uint8_t hash = mul_shift_hash(ht->rnd_hash_param, key);
    return chain_locate(ht->table + hash, key);
}


void ht_delete(HashTable* ht, uint32_t key) {
    uint8_t hash = mul_shift_hash(ht->rnd_hash_param, key);
    chain_remove(ht->table + hash, key);
}


void ht_free(HashTable* ht) {
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        chain_free(ht->table + i);        
    }
}

