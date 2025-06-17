#include <stdio.h>
#include <stdint.h>
#include <byteswap.h>

/*
 * Byte swap test:
 *
 * This experiment tests bswap_32() byte-swapping operation.
 */

int main(void)
{
	uint32_t val = 0xABCDEF12;
	uint32_t val2 = bswap_32(val);

	printf("bswap test: 0x%x -> 0x%x\n", val, val2);

	return 0;
}

