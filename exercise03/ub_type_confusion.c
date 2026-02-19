#include <stdio.h>
#include <stdint.h>

typedef void (*fn_int)(int);
typedef void (*fn_cstr)(const char *);

// Two structs that look the same in memory, but disagree on the function pointer type.
// Treating one as the other is undefined behavior (effective type + wrong function signature).
struct Safe {
    uint32_t tag;
    fn_int f;
};

struct Confused {
    uint32_t tag;
    fn_cstr f;
};

static void print_number(int x) {
    printf("print_number(int): x = %d\n", x);
}

static void print_first_char(const char *s) {
    // If s is invalid, dereferencing will likely crash.
    printf("print_first_char(const char*): first byte = 0x%02x\n", (unsigned char)s[0]);
}

int main(void) {
    struct Safe obj;
    obj.tag = 0xAABBCCDD;
    obj.f = print_number;

    // Type confusion: reinterpret Safe as Confused (same layout, different meaning).
    struct Confused *p = (struct Confused *)&obj;

    // Swap function pointer to a different signature than the object originally promised.
    p->f = print_first_char;

    printf("Triggering undefined behavior via type confusion...\n");

    // Use an intentionally invalid pointer to make the failure obvious.
    const char *bogus = (const char *)(uintptr_t)0x41414141u;

    p->f(bogus);

    printf("If you see this, it didn't crash (still undefined behavior).\n");
    return 0;
}
