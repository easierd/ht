#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "chain.h"


void chain_init(Chain* c) {
    c->head = NULL;
}


void chain_prepend(Chain* c, uint32_t key, char* item) {
    ChainNode* new_node = (ChainNode*) malloc(sizeof(ChainNode));

    new_node->next = c->head;
    new_node->prev = NULL;
    new_node->key = key;
    new_node->item = item;

    if (c->head) {
        c->head->prev = new_node;
    }

    c->head = new_node;
}


void chain_remove(Chain*c, uint32_t key) {
    ChainNode* n = c->head;
    while (n) {
        ChainNode* n_next = n->next;
        if (n->key == key) {

            if (n->prev) {
                n->prev->next = n->next;
            } else {
                c->head = n->next;
            }

            if (n->next) {
                n->next->prev = n->prev;
            }

            free(n);
        }
        n = n_next;
    }
}


char* chain_locate(Chain* c, uint32_t key) {
    ChainNode* n = c->head;
    while(n) {
        if (n->key == key) {
            return n->item;
        }
    }

    return NULL;
}


void chain_free(Chain* c) {
    while (c->head) {
        ChainNode* t = c->head->next;
        free(c->head);
        c->head = t;
    }
}


bool chain_empty(Chain* c) {
    return c->head == NULL;
}

