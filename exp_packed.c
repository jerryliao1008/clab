#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/*
 * Packed vs. Unpacked structure layout and alignment test:
 *
 * This test compares the size and alignment of packed and standard-aligned
 * structures to demonstrate how __attribute__((packed)) affects memory layout.
 */

/* Simple unpacked and packed struct */
struct header_unpacked {
	uint8_t command;
	bool is_response;
	bool has_next;
	uint16_t argument;
	uint8_t status;
};

struct header_packed {
	uint8_t command;
	bool is_response;
	bool has_next;
	uint16_t argument;
	uint8_t status;
} __attribute__((packed));

/* Nested struct test */
struct inner {
	int val;
};

struct outer_unpacked {
	char tag;
	struct inner in;
	uint8_t type;
};

struct outer_packed {
	char tag;
	struct inner in;
	uint8_t type;
} __attribute__((packed));

int main(void)
{
	printf("=== Basic Struct Comparison ===\n");
	printf("sizeof(header_unpacked) = %zu\n", sizeof(struct header_unpacked));
	printf("alignof(header_unpacked) = %zu\n", _Alignof(struct header_unpacked));
	printf("sizeof(header_packed) = %zu\n", sizeof(struct header_packed));
	printf("alignof(header_packed) = %zu\n", _Alignof(struct header_packed));

	printf("\n=== Nested Struct Comparison ===\n");
	printf("sizeof(inner) = %zu\n", sizeof(struct inner));
	printf("alignof(inner) = %zu\n", _Alignof(struct inner));

	printf("\n");

	printf("sizeof(outer_unpacked) = %zu\n", sizeof(struct outer_unpacked));
	printf("alignof(outer_unpacked) = %zu\n", _Alignof(struct outer_unpacked));
	printf("offsetof(outer_unpacked.tag) = %zu\n", offsetof(struct outer_unpacked, tag));
	printf("offsetof(outer_unpacked.in) = %zu\n", offsetof(struct outer_unpacked, in));
	printf("offsetof(outer_unpacked.type) = %zu\n", offsetof(struct outer_unpacked, type));

	printf("\n");

	printf("sizeof(outer_packed) = %zu\n", sizeof(struct outer_packed));
	printf("alignof(outer_packed) = %zu\n", _Alignof(struct outer_packed));
	printf("offsetof(outer_packed.tag) = %zu\n", offsetof(struct outer_packed, tag));
	printf("offsetof(outer_packed.in) = %zu\n", offsetof(struct outer_packed, in));
	printf("offsetof(outer_packed.type) = %zu\n", offsetof(struct outer_packed, type));

	return 0;
}
