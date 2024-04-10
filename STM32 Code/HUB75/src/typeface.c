#include "typeface.h"

/************** tetris board game **************/
const uint64_t board_pmap [] = 
{
  0xfffffffffff, 0xfffffffffff, 0xc0000000003, 0xc0000000003, 
  0xc0000000003, 0xc0000000003, 0xc0000000003, 0xc0000000003,
  0xc0000000003, 0xc0000000003, 0xc0000000003, 0xc0000000003,
  0xc0000000003, 0xc0000000003, 0xc0000000003, 0xc0000000003,
  0xc0000000003, 0xc0000000003, 0xc0000000003, 0xc0000000003,
  0xc0000000003, 0xc0000000003, 0xfffffffffff, 0xfffffffffff
};
const map_t board = {44, 24, board_pmap};

map_t
get_board (void)
{
  return board;
}

/************* _tetris board game_ *************/

/************** game shapes **************/ 
const uint64_t s_s1 [] = {0x00, 0x00, 0x0f, 0x0f, 0x3c, 0x3c, 0x00, 0x00};
const uint64_t s_s2 [] = {0x0c, 0x0c, 0x0f, 0x0f, 0x03, 0x03, 0x00, 0x00};
const map_t S [] = {{8, 2, s_s1}, {8, 2, s_s2}};

const uint64_t s_z1 [] = {0x00, 0x00, 0x3c, 0x3c, 0x0f, 0x0f, 0x00, 0x00};
const uint64_t s_z2 [] = {0x0c, 0x0c, 0x3c, 0x3c, 0x30, 0x30, 0x00, 0x00};
const map_t Z [] = {{8, 2, s_z1}, {8, 2, s_z2}};

const uint64_t s_i1 [] = {0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c};
const uint64_t s_i2 [] = {0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
const map_t I [] = {{8, 0, s_i1}, {8, 6, s_i2}}; // Used to be 4????

const uint64_t s_o1 [] = {0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00};
const map_t O [] = {{8, 2, s_o1}};

const uint64_t s_j1 [] = {0x30, 0x30, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00};
const uint64_t s_j2 [] = {0x0f, 0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00};
const uint64_t s_j3 [] = {0x00, 0x00, 0x3f, 0x3f, 0x03, 0x03, 0x00, 0x00};
const uint64_t s_j4 [] = {0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x0f, 0x0f};
const map_t J [] = {{8, 2, s_j1}, {8, 2, s_j2}, {8, 2, s_j3}, {8, 2, s_j4}};

const uint64_t s_l1 [] = {0x03, 0x03, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00};
const uint64_t s_l2 [] = {0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x0f, 0x00, 0x00};
const uint64_t s_l3 [] = {0x00, 0x00, 0x3f, 0x3f, 0x30, 0x30, 0x00, 0x00};
const uint64_t s_l4 [] = {0x3c, 0x3c, 0x0c, 0x0c, 0x0c, 0x0c, 0x00, 0x00};
const map_t L [] = {{8, 4, s_l1}, {8, 2, s_l2}, {8, 2, s_l3}, {8, 2, s_l4}};

const uint64_t s_t1 [] = {0x0c, 0x0c, 0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00};
const uint64_t s_t2 [] = {0x0c, 0x0c, 0x0f, 0x0f, 0x0c, 0x0c, 0x00, 0x00};
const uint64_t s_t3 [] = {0x00, 0x00, 0x3f, 0x3f, 0x0c, 0x0c, 0x00, 0x00};
const uint64_t s_t4 [] = {0x0c, 0x0c, 0x3c, 0x3c, 0x0c, 0x0c, 0x00, 0x00};
const map_t T [] = {{8, 4, s_t1}, {8, 2, s_t2}, {8, 2, s_t3}, {8, 2, s_t4}};

const map_t null_shape [] = {{0, 0, NULL}};

// all the game shapes
const shape_t shapes [] = {{S, 2}, {Z, 2}, {I, 2}, {O, 1}, {J, 4}, {L, 4}, {T, 4}, {null_shape, 0}};
const hub75_color_t shape_colors [] = {RED, GREEN, YELLOW, BLUE, PINK, TEAL, RED};

shape_t 
get_shape (uint8_t idx)
{
  if (idx >= NUM_SHAPES)
  {
    return shapes[NUM_SHAPES];
  }
  return shapes[idx];
}

hub75_color_t 
get_shape_color (uint8_t idx)
{
  if (idx >= NUM_SHAPES)
  {
    return BLACK;
  }
  return shape_colors[idx];
}
/************* _game shapes_ *************/
