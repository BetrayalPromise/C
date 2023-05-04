#include <stdio.h>
#include <stdlib.h>
#include "module_a.h"
#include "module_b.h"
#include "utils.h"

struct A {
    int a7;
};

int main(int argc, char ** argv) {
    // module_b$in$name(3);
    // module_test_0(3);
    // EasyFor(i, 0, 3, i ++) {

    // }
    // init(int, 3);
    // init(struct A, 5);
    return EXIT_SUCCESS;
}

static void before(void) __attribute__((constructor));
static void after(void) __attribute__((destructor));

static void before() {
    printf("before main\n");
}

static void after(void) {
    printf("after main\n");
}