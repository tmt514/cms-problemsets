#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include "LTiling.h"
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

vector<string> board;
int n, x, y, m;

bool inside(int a, int b) {
  return a >= 0 && a < m && b >= 0 && b < m;
}

char get_a_color(int cx, int cy, bool dx, bool dy) {
  const int fx[4]={1, 0, -1, 0};
  const int fy[4]={0, 1, 0, -1};
  static int u[128] = {}, ucs = 0;
  ++ucs;
  for(int i=0;i<4;i++) { 
    if(inside(cx+fx[i], cy+fy[i]))
      u[board[cx+fx[i]][cy+fy[i]]] = ucs;
    if(inside(cx+(dx?1:-1)+fx[i], cy+fy[i]))
      u[board[cx+(dx?1:-1)+fx[i]][cy+fy[i]]] = ucs;
    if(inside(cx+fx[i], cy+(dy?1:-1)+fy[i]))
      u[board[cx+fx[i]][cy+(dy?1:-1)+fy[i]]] = ucs;

  }
  for(int i='A';i<='Z';i++) if(u[i]!=ucs) return (char)i;
  return '#';
}

bool put_a_piece(int center_x, int center_y, bool dir_x, bool dir_y) {
  static int count = 0;
  ++count;

#ifndef EVAL
  fprintf(stderr, "PIECE %d: %d %d %d %d\n", count, center_x, center_y, dir_x, dir_y);
#endif
  if (inside(center_x, center_y) && inside(center_x + (dir_x?1:-1), center_y)
      && inside(center_x, center_y + (dir_y?1:-1))) {
    if (board[center_x][center_y] != '.' || board[center_x + (dir_x?1:-1)][center_y] != '.' || board[center_x][center_y + (dir_y?1:-1)] != '.') {

#ifndef EVAL
  fprintf(stderr, "ERROR: PIECE %d OCCUPIED SAME POSITION.\n", count);
#endif
      
    } else {
      char c = get_a_color(center_x, center_y, dir_x, dir_y);
      board[center_x][center_y] = board[center_x + (dir_x?1:-1)][center_y] = board[center_x][center_y + (dir_y?1:-1)] = c;
      printf("PIECE %d OK!\n", count);
#ifndef EVAL
      debug();
#endif
    }
  } else {
#ifndef EVAL
  fprintf(stderr, "ERROR: PIECE %d OUT OF BOUND.\n", count);
#endif
  }
  return true;
}

void debug(bool colorful) {
#ifndef EVAL
  puts("");
  puts("### DEBUG CALL");
  puts("");
  for(int i=0;i<m;i++) {
    printf("%s\n", board[i].c_str());
  }
  puts("");
#endif
  return;
}

int main(void) {
  scanf("%d%d%d", &n, &x, &y);
  board = vector<string>(1<<n);
  m = 1<<n;
  for (int i = 0; i < m; i++)
    board[i] = string(m, '.');
  board[x][y] = '*';
  
  LTiling t;
  t.tiling(n, x, y);
  puts("FINISH");
  return 0;
}
