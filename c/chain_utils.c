#include<stdio.h>

#include "chain_utils.h"

void chain_print(Chain* c) {
    printf("[");
    ChainNode* n = c->head;
    while(n) {
       printf("%s, ", n->item); 
       n = n->next;
    }
    printf("]\n");
}

