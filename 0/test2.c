#include <stdio.h>

void show() __attribute__((weak));

void show() {
    printf("test2.show()\n");
}