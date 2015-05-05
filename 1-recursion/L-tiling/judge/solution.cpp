#include "LTiling.h"
#include <cstdio>

void solve(int n, int x, int y, int ox=0, int oy=0) {
  if (n == 0) return;
  int m = (1<<(n-1));
  if (x < m && y < m) {
    put_a_piece(ox+m, oy+m, false, false);
    solve(n-1, x, y, ox, oy);
  } else {
    solve(n-1, m-1, m-1, ox, oy);
  }

  if (x >= m && y < m) {
    put_a_piece(ox+m-1, oy+m, true, false);
    solve(n-1, x-m, y, ox+m, oy);
  } else {
    solve(n-1, 0, m-1, ox+m, oy);
  }

  if (x < m && y >= m) {
    put_a_piece(ox+m, oy+m-1, false, true);
    solve(n-1, x, y-m, ox, oy+m);
  } else {
    solve(n-1, m-1, 0, ox, oy+m);
  }

  if (x >= m && y >= m) {
    put_a_piece(ox+m-1, oy+m-1, true, true);
    solve(n-1, x-m, y-m, ox+m, oy+m);
  } else {
    solve(n-1, 0, 0, ox+m, oy+m);
  }
}

void LTiling::tiling(int n, int x, int y) {
  /* Your codes starts here */
  solve(n, x, y);
}

