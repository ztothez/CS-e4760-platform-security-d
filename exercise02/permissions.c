// permissions.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Check if a character is a valid octal digit (0-7)
static int is_octal_digit(char c) {
    return (c >= '0' && c <= '7');
}

// Parse a 3-digit octal permission string like "755"
static int parse_perm_3oct(const char *s, int *out_perm) {
    if (!s || strlen(s) != 3) return 0;

    // Make sure all three chars are octal digits
    for (int i = 0; i < 3; i++) {
        if (!is_octal_digit(s[i])) return 0;
    }

    errno = 0;
    char *end = NULL;
    long v = strtol(s, &end, 8);  // Parse as base-8
    if (errno != 0) return 0;
    if (end == NULL || *end != '\0') return 0;
    if (v < 0 || v > 0777) return 0;  // Valid range check

    *out_perm = (int)v;
    return 1;
}

// Parse operations string like "rwx" or "rx" into a bitmask
static int parse_ops_mask(const char *ops, int *out_mask) {
    if (!ops) return 0;
    size_t n = strlen(ops);
    if (n == 0) return 0;

    int mask = 0;
    for (size_t i = 0; i < n; i++) {
        switch (ops[i]) {
            case 'r': mask |= 4; break;  // read = 4
            case 'w': mask |= 2; break;  // write = 2
            case 'x': mask |= 1; break;  // execute = 1
            default: return 0;           // invalid character
        }
    }
    *out_mask = mask;
    return 1;
}

// Check if user belongs to a given group
static int user_in_group(const char *file_group, int argc, char **argv, int start_idx) {
    for (int i = start_idx; i < argc; i++) {
        if (strcmp(argv[i], file_group) == 0) return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    // Expected arguments:
    // argv[1]: permission (3-digit octal like "755")
    // argv[2]: file owner
    // argv[3]: file group
    // argv[4]: operations string (like "rwx")
    // argv[5]: user attempting access
    // argv[6+]: user's groups (optional)

    if (argc < 6) {
        fprintf(stderr, "Invalid arguments.\n");
        fprintf(stderr, "Usage: permissions <perm> <owner> <group> <ops> <user> [groups...]\n");
        return 2;
    }

    int perm = 0;
    if (!parse_perm_3oct(argv[1], &perm)) {
        fprintf(stderr, "Invalid permission string.\n");
        return 2;
    }

    const char *file_owner = argv[2];
    const char *file_group = argv[3];
    const char *ops = argv[4];
    const char *user = argv[5];

    int req_mask = 0;
    if (!parse_ops_mask(ops, &req_mask)) {
        fprintf(stderr, "Invalid operations string.\n");
        return 2;
    }

    int class_bits = 0;

    // Decide which class applies: owner / group / other
    if (strcmp(user, file_owner) == 0) {
        class_bits = (perm >> 6) & 7;
    } else if (user_in_group(file_group, argc, argv, 6)) {
        class_bits = (perm >> 3) & 7;
    } else {
        class_bits = perm & 7;
    }

    // Check if all requested permission bits are present
    if ((class_bits & req_mask) == req_mask) {
        return 0;  // Access granted
    }
    return 1;      // Access denied
}
