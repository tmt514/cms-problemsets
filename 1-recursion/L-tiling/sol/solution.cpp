#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

void go(int n, int A, int B, int C) {
  if (n == 1) { printf("Move disk 1 from %d to %d.\n", A, B); return; }
  else {
    go(n-1, A, C, B);
    printf("Move disk %d from %d to %d.\n", n, A, B);
    go(n-1, C, B, A);
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  go(n, 1, 3, 2);
  return 0;
}
