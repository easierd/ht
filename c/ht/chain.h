/*
 * Chain implementation for the hash map
 * - chain are doubly linked lists 
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>


typedef struct ChainNode {
    uint32_t key;
    char* item;
    struct ChainNode* next;
    struct ChainNode* prev;
} ChainNode;


typedef struct Chain {
    ChainNode* head;
    size_t len;
} Chain;


void chain_init(Chain*);
void chain_prepend(Chain*, uint32_t, char*);
void chain_remove(Chain*, uint32_t);
char* chain_locate(Chain*, uint32_t);
void chain_free(Chain*);
bool chain_empty(Chain*);
size_t chain_length(Chain*);

