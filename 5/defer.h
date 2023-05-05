

static inline void handler(void (^ * expr)(void)) { (* expr)(); }

#define DEFER_1(x, y) x##y
#define DEFER_2(x, y) DEFER_1(x, y)
#define DEFER_0(x)    DEFER_2(x, __COUNTER__)
#define defer __attribute__((cleanup(handler))) void (^ DEFER_0(option))(void) = ^