#include <stdio.h>

/*
 * Callback function experiment:
 *
 * This test demonstrates how to pass a function pointer (callback)
 * that takes a single int argument. The main tester will call two
 * different callbacks to simulate logging and error handling.
 */

/* Callback to simulate logging a value */
int log_cb(int value)
{
	printf("log_cb: value = %d\n", value);
	return 0;
}

/* Callback to simulate error handling */
int error_cb(int value)
{
	if (value < 0)
		printf("error_cb: error! value = %d\n", value);
	else
		printf("error_cb: no error, value = %d\n", value);
	return value;
}

/* Function that accepts a callback and invokes it with a test value */
void test_cb(int (*callback_func)(int))
{
	printf("test_cb: invoking callback with 10\n");
	callback_func(10);

	printf("test_cb: invoking callback with -1\n");
	callback_func(-1);
}

int main(void)
{
	test_cb(log_cb);
	test_cb(error_cb);
	return 0;
}

