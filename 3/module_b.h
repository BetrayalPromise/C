#if !defined (Module) 
    #define Module module_b
#else
    #undef Module
    #define Module module_b
#endif

#if !defined (File) 
    #define File test
#else
    #undef File
    #define File test
#endif

#include "utils.h"

extern void func($, Module, in, name)(int a);