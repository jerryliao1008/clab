#include <stdio.h>

static struct vendor_id {
	const char *name;
	int pci_id;
	int iana_id;
} vendor_ids[] = {
	{"Adaptec", 0x9005, 0x31B},
	{"Intel"  , 0x8086, 0x157}
};

int main(void)
{
	int i;
	int array_size;

	array_size = sizeof(vendor_ids) / sizeof(vendor_ids[0]);

	for (i = 0; i < array_size; i++) {
		printf("name    = %s\n", vendor_ids[i].name);
		printf("pci_id  = 0x%x\n", vendor_ids[i].pci_id);
		printf("iana_id = 0x%x\n", vendor_ids[i].iana_id);
	}

	return 0;
}

