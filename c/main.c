#include<stdlib.h>
#include<stdio.h>

#include "ht/hash_table.h"
#include "utils/hash_table_utils.h"


int main(void) {
    HashTable ht;
    ht_init(&ht);

    // this will cause a leak 
    char* str = malloc(sizeof(char) * 5);
    str[0] = 'a';
    str[1] = 'a';
    str[2] = 'a';
    str[3] = 'a';
    str[4] = 0;

    ht_insert(&ht, 25, str);
    ht_insert(&ht, 25, "sanvi");
    ht_insert(&ht, 324, "consomdsf");
    ht_insert(&ht, 234, "c programming");
    ht_insert(&ht, 3240, "hash_table");

    ht_print(&ht);

    ht_delete(&ht, 25);
    ht_delete(&ht, 26);

    ht_print(&ht);

    ht_free(&ht);
    free(str);
}

