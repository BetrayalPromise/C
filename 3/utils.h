#ifndef __UTILS_H__
#define __UTILS_H__

#if !defined (__$NAMESPACE$__) && !defined (__NAMESPACE__)
    #define __$NAMESPACE$__(s, Module, File, Name) Module##s##File##s##Name
    #define __NAMESPACE__(s, Module, File, Name) __$NAMESPACE$__(s, Module, File, Name)
#else
    #warning "information: other module define macro '__$NAMESPACE$__' or '__NAMESPACE__'!"
#endif
    
#if !defined(func)
    // Module: 模块名称
    // File: 文件名称不带后缀
    // Name: 函数名
    // s:分割符号 C语言允许的函数名分隔符只有两种(_和$)其他的不允许使用
    #define func(s, Module, File, Name) __NAMESPACE__(s, Module, File, Name)
#else
    #warning "information: other module also define macro 'func'!"
#endif

#if !defined ($$) && !defined (__)
    #define $$(Module, File, Name) func($, Module, File, Name)
    #define __(Module, File, Name) func(_, Module, File, Name)
#else
    #warning "information: other module also define macro '$$' or '__'!"
#endif


#if !defined (init) && !defined (deinit)
    #define init(type, n) ((type *)malloc((n) * sizeof(type)))
    #define deinit(var) (free(var); var = NULL);
#else
    #warning "information: other module also define macro 'init' or 'deinit'!"
#endif

#if !defined (Stringfy) && !defined (Println)
    #define Stringfy(x) #x
    #define Println putchar('\n')
#else
    #warning "information: other module also define macro 'Stringfy' or 'ln'!"
#endif

#if !defined(weak) && !defined (strong)
    #define weak __attribute__((weak))
    #define strong
#else
    #warning "information: other module also define macro 'weak' or 'strong'!"
#endif

#if !defined(EasyFor)
    #define EasyFor(var, start, stop, ...) for (int var = start; var < stop; __VA_ARGS__)
#else
    #warning "information: other module also define macro 'EasyFor'!"
#endif

#if !defined(Minimum) && !defined (Maximum)
    #define Minimum(type, x, y) ({ type __min1 = (x); type __min2 = (y); __min1 < __min2 ? __min1 : __min2; })
    #define Maximum(type, x, y) ({ type __max1 = (x); type __max2 = (y); __max1 > __max2 ? __max1 : __max2; })
#else
    #warning "information: other module also define macro 'Minimum' or 'Maximum'!"
#endif

#if !defined(GenericType)
    #define GenericType(v) _Generic((v), bool: "bool", char: "char", short: "short", int: "int", long: "long", unsigned short: "ushort",unsigned int: "uint", unsigned long: "ulong", float: "float", double: "double", char *: "char *", bool *: "pbool", short *: "pshort", int *: "pint", long *: "plong", unsigned short *: "pushort", unsigned int *: "puint", unsigned long *: "pulong", float *: "pfloat", double *: "pdouble", default: "unsupport type")default: "unsupport type")
#else
    #warning "information: other module also define macro 'GenericType'!"
#endif

#endif