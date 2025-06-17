#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
 * Simple calloc() test:
 *
 * Allocate a buffer with calloc(), verify initialization to zero,
 * write test pattern into the buffer, and print first few values.
 */
int main(void)
{
    uint8_t *buf = NULL;
    int i;

    buf = calloc(1, 512);
    if (!buf) {
        printf("calloc failed!\n");
        return -1;
    }

    for (i = 0; i < 512; i++)
        buf[i] = i;

    for (i = 0; i < 9; i++)
        printf("buf[%d] = %d\n", i, buf[i]);

    free(buf);
    return 0;
}
