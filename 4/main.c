#include <stdio.h>
#include <stdlib.h>
#include "defer.h"

void foo1();

struct A {

};

int main(int argc, char ** argv) {
    
    DeferBegin(0);
    int * p = malloc(sizeof(struct A));
    if (!p) return 1;
    defer({
        printf("defer A\n");
    });

    defer({
        printf("defer B\n");
    });

    printf("malloc memory\n");
    DeferEnd();
    return EXIT_SUCCESS;
}

void foo1() {
    printf("B");
}