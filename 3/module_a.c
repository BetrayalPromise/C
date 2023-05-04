#include "module_a.h"
#include <stdio.h>
#include <stdlib.h>

void func(_, module, test, 0)(int a) {
    printf("%s\n", __FUNCTION__);
}
