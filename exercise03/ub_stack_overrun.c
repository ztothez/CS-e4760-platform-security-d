#include <stdio.h>
#include <stdint.h>

// Demonstrates undefined behavior: write past the end of a stack buffer.
// What happens depends on the compiler, flags, and stack layout (crash, corruption, or "seems fine").

static void demo_stack_overrun(void) {
    // Volatile keeps the demo honest (prevents some optimizations).
    volatile uint64_t secret = 0x1122334455667788ULL;

    // Small buffer on the stack.
    volatile unsigned char buf[8];

    // Initialize buf with predictable values.
    for (int i = 0; i < 8; i++) {
        buf[i] = (unsigned char)i;
    }

    printf("Before overrun: secret = 0x%016llx\n", (unsigned long long)secret);

    // Deliberate overflow: buf is 8 bytes, but we write past it.
    // This is undefined behavior and may overwrite nearby locals, saved registers, or return address.
    for (int i = 8; i < 32; i++) {
        buf[i] = 0xAA;
    }

    // If secret sits next to buf in the current stack layout, it may change.
    printf("After  overrun: secret = 0x%016llx\n", (unsigned long long)secret);

    // Small guard to keep buf "used" in a visible way.
    if (buf[0] == 0xFF) {
        printf("Impossible branch\n");
    }
}

int main(void) {
    demo_stack_overrun();
    return 0;
}
