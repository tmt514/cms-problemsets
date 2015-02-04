#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

const LL MOD = 1e9+7;

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

int main(void) {
  
  Matrix A = Matrix(), P = Matrix(1, 1, 1, 0);

  string s;
  cin >> s;
  for (int i = 0; i < SZ(s); i++) {
    for (int j = '0'; j < s[i]; j++) {
      A = A * P;
    }
    if (i+1 < SZ(s)) {
      Matrix Q = A;
      for (int j = 0; j < 9; j++)
        A = A * Q;
    }
  }

  cout << A.a[1][0] << endl;
  
  return 0;
}
