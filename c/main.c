#define TYPE char*

#include "chain.h"
#include "chain_utils.h"

#include "hash_table.h"
#include "hash_table_utils.h"

int main(void) {
    HashTable ht;
    ht_init(&ht);

    ht_insert(&ht, 25, "ciao");
    ht_insert(&ht, 26, "ciao");

    ht_print(&ht);

    ht_delete(&ht, 25);
    ht_delete(&ht, 26);

    ht_print(&ht);

    ht_free(&ht);
}
