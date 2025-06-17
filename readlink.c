#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*
 * Simple readlink() test:
 * 
 * This program attempts to read the target of a symbolic link 
 * at a specified path, and prints the resolved target path.
 *
 * Note: readlink() does not null-terminate the result.
 */
int main(void)
{
    char link_path[] = "/sys/class/i2c-dev/i2c-20/device/mux_device";
    char target_path[256];
    ssize_t len;

    len = readlink(link_path, target_path, sizeof(target_path) - 1);
    if (len == -1)
        printf("Fail to read link path !!\n");
    else {
        target_path[len] = '\0';
        printf("link path is %s\n", target_path);
    }

    return 0;
}

