#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_INPUT 64

static void banner(void) {
    puts("=== Validation Lab ===");
    puts("This binary is intended for local reverse-engineering practice.");
    puts("Enter access code:");
}

static void trim_newline(char *s) {
    size_t n = strlen(s);
    if (n > 0 && (s[n - 1] == '\n' || s[n - 1] == '\r')) {
        s[n - 1] = '\0';
        n--;
    }
    if (n > 0 && s[n - 1] == '\r') {
        s[n - 1] = '\0';
    }
}

static void normalize_input(char *dst, const char *src) {
    size_t i = 0;
    while (src[i] != '\0' && i < MAX_INPUT - 1) {
        char c = src[i];
        if (c >= 'a' && c <= 'z') {
            c = (char)(c - 32);
        }
        dst[i] = c;
        i++;
    }
    dst[i] = '\0';
}

static void obfuscate(char *dst, const char *src) {
    static const uint8_t key[] = {0x13, 0x37, 0x21, 0x09, 0x42, 0x18, 0x5A, 0x0C};
    size_t i = 0;
    while (src[i] != '\0' && i < MAX_INPUT - 1) {
        dst[i] = (char)(src[i] ^ key[i % sizeof(key)]);
        i++;
    }
    dst[i] = '\0';
}

static int validate_code(const char *user_input) {
    char normalized[MAX_INPUT];
    char transformed[MAX_INPUT];

    /* Correct input after normalization: DEBUG-LAB */
    static const unsigned char expected[] = {
        0x57, 0x72, 0x63, 0x5C, 0x05, 0x35, 0x1B, 0x4D, 0x51, 0x76, 0x00
    };

    normalize_input(normalized, user_input);
    obfuscate(transformed, normalized);

    return strcmp(transformed, (const char *)expected) == 0;
}

static void show_success(void) {
    puts("Access granted");
    puts("Status: VALID");
}

static void show_error(void) {
    puts("Access denied");
    puts("Status: INVALID");
}

int main(void) {
    char input[MAX_INPUT];

    banner();

    if (fgets(input, sizeof(input), stdin) == NULL) {
        show_error();
        return 1;
    }

    trim_newline(input);

    if (validate_code(input)) {
        show_success();
        return 0;
    }

    show_error();
    return 1;
}
