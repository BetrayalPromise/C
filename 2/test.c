#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define GET_TYPE(var) _Generic((var), char: "char", short: "short", int: "int", long: "long", unsigned short: "unsigned short", unsigned int: "unsigned int", unsigned long: "unsigned long", float: "float", double: "double", char *: "char *", default: "other type")
#define FUNC(X, Y) _Generic((X), int: func_int, double: func_double, float: func_float)(X, Y)

int func_int(int x, int y) {
    printf("call func_int.\n");
    return x + y;
}

double func_double(double x, double y) {
    printf("call func_double.\n");
    return x + y;
}

float func_float(float x, float y) {
    printf("call func_float.\n");
    return x + y;
}

int main() {
    int x1 = 2, y1 = 3;
    printf("%s\n", GET_TYPE(3));
    printf("%d\n", FUNC(x1, y1));
    return 0;
}

