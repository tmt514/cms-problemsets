#include <stdio.h>
#include <assert.h>
#include "reverse_add.h"

void reportAnswer(int a, int b) {
    printf("%d %d\n", a, b);
}

int main() {
    int x;
    assert(scanf("%d", &x) == 1);
    reverseAdd(x);
    return 0;
}
