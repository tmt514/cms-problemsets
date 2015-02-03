#include <iostream>

using namespace std;

typedef long long LL;

LL factorial(int n) {
  if (n == 0) return 1LL;

  return n * factorial(n-1);
}

int main(void) {
  int n;
  cin >> n;

  cout << factorial(n) << endl;
  return 0;
}
