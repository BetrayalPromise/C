#ifndef __DEFER_H__
#define __DEFER_H__

#include <assert.h>
#include <stdbool.h>

#if !defined(_LABEL_) && !defined(__LABEL__) && !defined(___LABEL___)
    #define _LABEL_(x) _LABEL_##x
    #define __LABEL__(x) _LABEL_(x)
    #define ___LABEL___ __LABEL__(__LINE__)
#else
    #warning "information: other module also define macro '_LABEL_', '__LABEL__', '___LABEL___'!"
#endif

#if !defined(DeferBegin) && !defined(defer) && !defined(DeferEnd)
    #define DeferBegin(number)\
        void * _defers_[number];\
        void * _run_;\
        int _index_ = 0;\
        int _number_ = number;\

    #define defer(code) \
        if (_index_ > _number_ - 1) {\
            printf("number too smaller!");\
            assert(0);\
        };\
        _defers_[_index_ ++] = && ___LABEL___;\
        if (0) {\
            ___LABEL___:code;\
            if (_index_ --) goto *_defers_[_index_];\
            else goto *_run_;\
        }

    #define DeferEnd()\
        _run_ = && ___LABEL___;\
        if (_index_--)\
            goto *_defers_[_index_];\
        ___LABEL___:
#else
    #warning "information: other module also define macro 'DeferBegin', 'defer', 'DeferEnd'!"
#endif

#endif