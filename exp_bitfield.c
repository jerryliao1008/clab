#include <stdio.h>
#include <stdint.h>

/*
 * Bit-field syntax and struct layout test:
 *
 * This experiment demonstrates the usage of bit-field syntax (:) in C struct definitions,
 * and observes how bitfields are packed into memory.
 */

struct test {
	uint8_t data1;
	uint8_t data2;
	uint8_t enable : 1;  /* 1-bit field */
	uint8_t mode   : 5;  /* 5-bit field */
	uint8_t status : 2;  /* 2-bit field */
	uint8_t data3;
};

int main(void)
{
	uint8_t *buf;
	struct test t;
	int i;

	t.data1 = 8;
	t.data2 = 9;
	t.enable = 1;
	t.mode = 9;
	t.status = 1;

	buf = (uint8_t *)&t;

	for (i = 0; i < sizeof(struct test); i++)
		printf("buf[%d] = 0x%x\n", i, buf[i]);

	printf("sizeof struct test = %zu\n", sizeof(struct test));

	return 0;
}

