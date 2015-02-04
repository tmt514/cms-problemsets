#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9+7; /* 要記得輸出除以 1e9+7 的餘數 */

int fib(int n) {

  /* 設定遞迴終止條件 */
  if (n == 0) {
    return n;
  }

  /* 遞迴式 */
  return fib(n-1) + fib(n-2);
}

int main(void) {
  int n;
  /* 輸入 */
  cin >> n;

  /* 計算與輸出 */
  cout << fib(n) << endl;
  return 0;
}
