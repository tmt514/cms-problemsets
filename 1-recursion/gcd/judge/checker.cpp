#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
  ifstream data_in(argv[1]);
  ifstream data_out(argv[2]);
  ifstream user_out(argv[3]);
  LL D, X, Y;
  user_out >> D >> X >> Y;
  LL A, B, P = -1;
  data_in >> A >> B;
  data_out >> P;
  string zzz;
  user_out >> zzz;
  if (!user_out.eof()) {
    cerr << "User input not end!" << endl;
    cout << "0.0" << endl;
    return 0;
  }
  if ( D != P ) {
    cerr << "GCD does not agree!" << endl;
    cout << "0.0" << endl;
    return 0;
  }
  if (abs(X) > 1e9 && abs(Y) > 1e9) {
    cerr << "X or Y out of range!" << endl;
    cout << "0.4" << endl;
    return 0;
  }
  if (D != A*X+B*Y) {
    cout << "0.4" << endl;
    return 0;
  }
  cout << "1.0" << endl;
  return 0;
}
