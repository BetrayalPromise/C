#include <stdint.h>
#include <stdio.h>
#include <sys/resource.h>
#include "module_b.h"


#define DEFARG(para, defval)    ((#para[0]) ? (para + 0) : defval)
#define Func(i)                  default_value(DEFARG(i, 22));

void default_value(int i) {

}

void func($, Module, in, name)(int a) {
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __PRETTY_FUNCTION__);
    printf("%s\n", __func__);
    printf("%s\n", __FILE_NAME__);
    printf("%ld\n", __STDC_VERSION__);
}

void $$(a, b, c)(void) {
    
}

weak void __(c, d, e)(void) {
    EasyFor(i, 0, 3, i += 2) {

    }
}