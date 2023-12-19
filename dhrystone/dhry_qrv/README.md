# Minor Changes before building the benchmark

In file src/platform/sifive/qemu-sifive-e/config.mk, change
- `HEAP_SIZE` to 2K
- `STACK_SIZE` to 0x200
- `STACK_SIZE_PCPU` to 0x200
