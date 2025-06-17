#include <stdio.h>
#include <stdlib.h>

/*
 * Bitwise AND test with multiple bits:
 *
 * This experiment tests bitwise AND operation by checking multiple bit positions.
 */

int main(void)
{
	unsigned char reg_val = 0x06;
	unsigned char bit_mask[4];
	int i;

	printf("reg: 0x%x\n", reg_val);

	/* Create bit mask and check each bit */
	for (i = 0; i < 4; i++) {
		bit_mask[i] = 1 << i;

		if (reg_val & bit_mask[i])
			printf("bit %d is set\n", i);
		else
			printf("bit %d is not set\n", i);
	}

	return 0;
}