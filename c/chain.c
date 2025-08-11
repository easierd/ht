#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "chain.h"

void chain_init(Chain* c) {
    c->head = NULL;
}

void chain_prepend(Chain* c, char* item) {
    ChainNode* new_node = (ChainNode*) malloc(sizeof(ChainNode));


    new_node->next = c->head;
    new_node->prev = NULL;
    new_node->item = item;

    if (c->head) {
        c->head->prev = new_node;
    }

    c->head = new_node;
}


void chain_remove(Chain*c, char* item) {
    ChainNode* n = c->head;
    while (n) {
        ChainNode* n_next = n->next;
        if (strcmp(n->item, item) == 0) {

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


void chain_free(Chain* c) {
    while (c->head) {
        ChainNode* t = c->head->next;
        free(c->head);
        c->head = t;
    }
}
