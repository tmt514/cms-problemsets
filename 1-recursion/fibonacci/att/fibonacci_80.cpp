#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9+7; /* 要記得輸出除以 1e9+7 的餘數 */

class Matrix {
  public:
    LL a[2][2];
    Matrix(LL A=1, LL B=0, LL C=0, LL D=1) {
      a[0][0] = A;
      a[1][0] = B;
      a[0][1] = C;
      a[1][1] = D;
    }
    Matrix(const Matrix &p) {
      for (int i = 0; i < 4; i++)
        a[i/2][i%2] = p.a[i/2][i%2];
    }
    Matrix operator *(const Matrix &p) {
      Matrix r;
      r.a[0][0] = (a[0][0] * p.a[0][0] + a[0][1] * p.a[1][0]) % MOD;
      r.a[0][1] = (a[0][0] * p.a[0][1] + a[0][1] * p.a[1][1]) % MOD;
      r.a[1][0] = (a[1][0] * p.a[0][0] + a[1][1] * p.a[1][0]) % MOD;
      r.a[1][1] = (a[1][0] * p.a[0][1] + a[1][1] * p.a[1][1]) % MOD;
      return r;
    };
};


Matrix fib(LL n) {
  if (n == 0) {
    return Matrix(0, 0, 0, 0);
  } else if (n == 1) {
    return Matrix(1, 1, 1, 0);
  }
  
  /* We use recursion, and divide the power by 2 */
  if (n%2 == 0) {
    return fib(n/2) * fib(n/2);
  } else {
    return fib(n/2) * fib(n/2) * Matrix(1, 1, 1, 0);
  }
}

int main(void) {
  LL n;
  cin >> n;

  Matrix ans = fib(n);

  cout << ans.a[0][1] << endl;
  return 0;
}
