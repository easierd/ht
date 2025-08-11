#include<stdio.h>

#include "chain_utils.h"


void chain_print(Chain* c) {
    ChainNode* n = c->head;
    while(n) {
       printf("{%u: %s}", n->key, n->item); 
       if (n->next) {
            printf(",");
       }
       n = n->next;
    }
}

