
// static inline void handler(void (^ * expr)(void)) { (* expr)(); }
// #define DEFER_1(x,y) x##y
// #define DEFER_2(x, y) DEFER_1(x, y)
// #define DEFER_0(x)    DEFER_2(x, __COUNTER__)
// #define defer __attribute__((cleanup(handler))) void (^ DEFER_0(option))(void) =

 #define DEFER_MAX    10
 #define defer_start\
    void * _defer_stack[DEFER_MAX];\
    void * _defer_run;\
    int  _defer_stack_index = 0;

 #define ___defer_label(x)   _defer_label_ ## x
 #define __defer_label(x)    ___defer_label(x)
 #define _defer_label        __defer_label(__LINE__)

 #define defer(code) \
    if(_defer_stack_index > DEFER_MAX - 1) { printf("DEFER_MAX too smaller"); };\
    _defer_stack[_defer_stack_index ++] = && _defer_label;\
    if (0) {\
        _defer_label:code;\
        if (_defer_stack_index --) goto *_defer_stack[_defer_stack_index];\
        else goto *_defer_run;\
    }
#define defer_stop\
    _defer_run = && _defer_label;\
    if (_defer_stack_index--)\
        goto *_defer_stack[_defer_stack_index];\
    _defer_label:



#include <stdio.h>
#include <stdlib.h>

void foo1();

struct A {

};

int main(int argc, char ** argv) {
    defer_start;
    int * p = malloc(sizeof(struct A));
    if (!p) 
        return 1;

    defer({
        printf("defer \n");
        free(p);
    });
    printf("malloc memory\n");
    defer_stop;
    return EXIT_SUCCESS;
}

void foo1() {
    printf("B");
}