# clab

C Lab — Personal C language experiment playground.

This repo contains simple experiments, tests, and validation code for various C language features, library functions, and system APIs.

## Build

```bash
make
```

- All `.c` files in the repository will be automatically compiled into corresponding binaries.
- No need to modify `Makefile` when adding new experiments.
- By default, `arm-linux-gnueabi-gcc` is used as the cross-compiler.
- You can override the compiler when building:

```bash
make CC=gcc
```

## Current experiments

- `exp_and.c` - Bitwise AND operation test
- `exp_bitfield.c` - Bit-field syntax and memory layout test
- `exp_bswap.c` - Byte swap operation test
- `exp_callback.c` - Function pointer callback test with log and error handlers
- `exp_calloc.c` - Memory allocation test (`calloc`)
- `exp_enum.c` - Enum value assignment and auto-increment behavior
- `exp_packed.c` - Compare size, alignment, and layout of packed vs. unpacked structures, including nested struct scenarios.
- `exp_readlink.c` - Test POSIX `readlink()` behavior
