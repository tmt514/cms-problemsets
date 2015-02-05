#ifndef L_TILING_H
#define L_TILING_H

class LTiling {
  public:
    void tiling(int n, int x, int y);
};

bool put_a_piece(int center_x, int center_y, bool dir_x, bool dir_y);
void debug(bool colorful = false);

#endif
