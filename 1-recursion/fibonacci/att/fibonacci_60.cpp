#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9+7; /* 要記得輸出除以 1e9+7 的餘數 */

LL fib(int n) {
  LL F_n_plus_2 = 2, F_n_plus_1 = 1, F_n = 1;
  for (int i = 0; i < n; i++) {
    F_n        = F_n_plus_1;
    F_n_plus_1 = F_n_plus_2;
    F_n_plus_2 = F_n_plus_1 + F_n;
  }
  return F_n % MOD;
}

int main(void) {
  int n;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}
