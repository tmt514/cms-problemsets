#include <cstdio>
#include <cstdlib>
#include <cassert>

#define FAIL(fmt, ...) do { \
    puts("0.0"); \
    fprintf(stderr, fmt "\n", ##__VA_ARGS__); \
    exit(0); \
} while (false);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s input answer output\n", argv[0]);
        exit(1);
    }

    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[3], "r");
    assert(fin != NULL);
    assert(fout != NULL);

    int x, a, b;
    assert(fscanf(fin, "%d" ,&x) == 1);
    if (fscanf(fout, "%d%d", &a, &b) != 2) FAIL("output format error");
    if (a + b != x) FAIL("Wrong Answer");

    puts("1.0");
    fprintf(stderr, "OK");
    return 0;
}
