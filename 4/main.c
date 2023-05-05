
static inline void handler(void (^ * expr)(void)) { (* expr)(); }
#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_0(x)    DEFER_2(x, __COUNTER__)
#define defer __attribute__((cleanup(handler))) void (^ DEFER_0(option))(void) = ^

#include <assert.h>
#include <stdbool.h>

//  #define ___LABEL___(x)   ___LABEL___ ## x
//  #define __LABEL__(x)    ___LABEL___(x)
//  #define _LABEL_        __LABEL__(__LINE__)

//  #define begin(number)\
//     void * _defers_[number];\
//     void * _run_;\
//     int  _index_ = 0;\
//     int _number_ = number;

//  #define defer(code) \
//     if (_index_ > _number_ - 1) {\
//         printf("number too smaller!");\
//         assert(false);\
//     };\
//     _defers_[_index_ ++] = && _LABEL_;\
//     if (0) {\
//         _LABEL_:code;\
//         if (_index_ --) goto *_defers_[_index_];\
//         else goto *_run_;\
//     }

// #define end()\
//     _run_ = && _LABEL_;\
//     if (_index_--)\
//         goto *_defers_[_index_];\
//     _LABEL_:

#include <stdio.h>
#include <stdlib.h>

void foo1();

struct A {

};

int main(int argc, char ** argv) {
    // begin(10);
    // int * p = malloc(sizeof(struct A));
    // if (!p) return 1;

    // defer({
    //     printf("defer A\n");
    // });

    // defer({
    //     printf("defer B\n");
    // });
    // printf("malloc memory\n");
    // end();

    defer {
        printf("defer B\n");
    };
    printf("B--\n");
    defer {
        printf("defer A\n");
    };
    printf("A--\n");
    return EXIT_SUCCESS;
}

void foo1() {
    printf("B");
}