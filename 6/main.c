#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defer.h"

void test1(void) {
	Deferral();
	char *x = malloc(0x100);
	defer(free(x));

	/* legal because deconstruction happens in reverse order */
	defer({
		printf("x is %s\n", x);
		x[1]++;
		printf("now %s\n", x);
	});

	strcpy(x, "Hello world");

	Return;
}

int test2(void) {
	Deferral();
	puts("1");

	/* caveat: unlike in other programming languages, the return expression
	 * is evaluated after deferred statements.  Unfortunately, there is no
	 * good way around this.
	 */
	defer(puts("2"));
	Return puts("3");
}

int main(void) {
	test1();
	return test2();
}