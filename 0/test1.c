#include <stdio.h>
#include <stdlib.h>
// #include "test2.c"

void show() __attribute__((weak));

int main (int argc, char ** argv) {
    show();
    return EXIT_SUCCESS;
}

void show() {
    printf("test1.show()\n");
}
