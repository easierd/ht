#define TYPE char*

#include "chain.h"
#include "chain_utils.h"

int main(void) {
    Chain c;
    chain_init(&c);

    chain_prepend(&c, "ciao");

    chain_print(&c);

    chain_free(&c);
}
