/*
 * Chain implementation for the hash map
 * - chain are doubly linked lists 
 */

#pragma once

typedef struct ChainNode {
   char* item;
   struct ChainNode* next;
   struct ChainNode* prev;
} ChainNode;


typedef struct Chain {
    ChainNode* head;
} Chain;

void chain_init(Chain*);
void chain_prepend(Chain*, char*);
void chain_remove(Chain*, char*);
void chain_free(Chain*);

