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
/*
  8 5
  5 3
  3 2    3 * X + 2 * (Y-1*X)   = D
  2 1    2 * X + 1 * (Y-2*X)   = D
  1 0    1 * X + 0 * Y   = D
*/
LL go(LL A, LL B, LL &X, LL &Y) {
  if (B == 0) { X = 1; Y = 0; return A; }
  LL D = go(B, A%B, Y, X);
  Y -= (A/B)*X;
  return D;
}

int main(void) {
  LL A, B, X, Y;
  scanf("%lld%lld", &A, &B);
  LL D = go(A, B, X, Y);
  printf("%lld %lld %lld\n", D, X, Y);
  return 0;
}
