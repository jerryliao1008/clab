#include <stdio.h>
#include <stdlib.h>

/*
 * Simple enum test:
 *
 * This experiment demonstrates enum value assignment,
 * including automatic increment and manual override.
 */
enum message {
    TYPE_CTRL = 0,
    TYPE_PLDM,
    TYPE_VDM_PCI = 126,
    TYPE_VDM_IANA,
    TYPE_MAX
};

int main(void)
{
    printf("TYPE_PLDM = %d\n", TYPE_PLDM);
    printf("TYPE_VDM_IANA = %d\n", TYPE_VDM_IANA);
    printf("TYPE_MAX = %d\n", TYPE_MAX);
    return 0;
}
