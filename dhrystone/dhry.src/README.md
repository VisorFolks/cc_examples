# Dhrystone benchmark for Cyancore platform

This project consists of dhyrstone benchmark upstream sources, separated into 2 files dhry.c and dhryR.c

- dhry.c is regular benchmark
- dhryR.c is benchmark utilizing registers instead of memory.

### Project Porting
A project port or any target should define following macros
- `HZ`, which is clock frequency
- `MODE_REGISTER`, to use register benchmark
