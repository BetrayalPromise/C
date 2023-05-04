#if !defined (Module) 
    #define Module AK47
#else
    #undef Module
    #define Module AK47
#endif

#if !defined (File) 
    #define File test
#else
    #undef File
    #define File test
#endif

#include "utils.h"

extern void func(_, module, test, 0)(int a);
