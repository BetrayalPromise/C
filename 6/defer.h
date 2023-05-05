#ifndef __DEFER_H__
#define __DEFER_H__

#ifndef DEFER_MAX_DEFERRED_STATEMENTS
# define DEFER_MAX_DEFERRED_STATEMENTS 32
#endif

#if defined(__GNUC__) || defined(__TINYC__)

#define Deferral(number) \
unsigned char _deferrals_ = 0; \
void *_defer_return_loc = 0, *_deferrals[DEFER_MAX_DEFERRED_STATEMENTS] = {0};

#ifdef __PCC__
	# define defer(block) _Defer(block, __LINE__)
	# define Return _Return(__LINE__)
#else
	# define defer(block) _Defer(block, __COUNTER__)
	# define Return _Return(__COUNTER__)
#endif

#define _defer_tokpaste(a, b) a ## b

#define _Defer(block, n) do { \
	_deferrals[_deferrals_++] = && _defer_tokpaste(_defer_ini, n); \
	if (0) { \
		_defer_tokpaste(_defer_ini, n): \
		block; \
		if (_deferrals_) { \
			goto *_deferrals[--_deferrals_]; \
		} else { \
			goto *_defer_return_loc; \
		} \
	} \
} while (0)

#define _Return(n) \
	if (_deferrals_) { \
		_defer_return_loc = && _defer_tokpaste(_defer_fini_, n); \
		goto *_deferrals[--_deferrals_]; \
	} else _defer_tokpaste(_defer_fini_, n): return

#else /* !__GNUC__ && !__TINYCC__ */

#include <setjmp.h>

#ifdef _MSC_VER
	# pragma message("You are using the unsafe longjmp()-based defer implementation.  Expect bugs if you don't know what you're doing.")
#else
	# warning You are using the unsafe longjmp()-based defer implementation.  Expect bugs if you don't know what you're doing.
#endif

#define Deferral \
volatile unsigned char _deferrals_ = 0; \
jmp_buf _defer_return_loc = {0}, _deferrals[DEFER_MAX_DEFERRED_STATEMENTS] = {0};

#define Defer(block) do { \
	if (setjmp(_deferrals[_deferrals_++])) { \
		block; \
		if (_deferrals_) { \
			longjmp(_deferrals[--_deferrals_], 1); \
		} else { \
			longjmp(_defer_return_loc, 1); \
		} \
	} \
} while (0)

#define Return \
	if (!setjmp(_defer_return_loc)) { \
		if (_deferrals_) longjmp(_deferrals[--_deferrals_], 1); \
	} else return

#endif /* __GNUC__ */

#endif /*__DEFER_H__*/