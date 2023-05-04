#include <stdio.h>
#include <stdlib.h>

#define CALL(name) call_##name

// 变量名称(字符串型)
#define NAME(x) #x

#define public __attribute__((visibility("default")))
#define private __attribute__((visibility("hidden")))

