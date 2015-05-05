#include <stdio.h>
#include <assert.h>
#include "add.h"

int main() {
    int a, b;
    assert(scanf("%d%d", &a, &b) == 2);
    int ans = addTwoNumbers(a, b);
    printf("%d\n", ans);
    return 0;
}
