//#pragma once
#ifndef ATTACK25_BLE_H_
#define ATTACK25_BLE_H_


#include "custom_board.h"

#define THIS_DEVICE_ROWS 5
#define THIS_DEVICE_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS            \
  {                                \
    PIN7, PIN8, PIN9, PIN19, PIN18 \
  }
/* PIN11, PIN12, PIN13, PIN14, PIN15  */

#define MATRIX_COL_PINS               \
  {                                   \
    PIN11, PIN12, PIN13, PIN14, PIN15 \
  }
/*     PIN7, PIN8, PIN9, PIN19, PIN18  */

//#define MATRIX_ROW_PINS { B4, B5, B6, B2, B3 }
//#define MATRIX_COL_PINS { D4, C6, D7, F5, F6 }
//#define UNUSED_PINS

#ifdef BLE_MICRO_PRO

#define LAYOUT_ortho_5x5(          \
    K00, K01, K02, K03, K04,       \
    K10, K11, K12, K13, K14,       \
    K20, K21, K22, K23, K24,       \
    K30, K31, K32, K33, K34,       \
    K40, K41, K42, K43, K44)       \
  {                                \
    {K00, K10, K20, K30, K40},     \
        {K01, K11, K21, K31, K41}, \
        {K02, K12, K22, K32, K42}, \
        {K03, K13, K23, K33, K43}, \
    {                              \
      K04, K14, K24, K34, K44      \
    }                              \
  }

#define LAYOUT LAYOUT_ortho_5x5
#define IS_LEFT_HAND  true

#else

#define LAYOUT_ortho_5x5(          \
    K00, K01, K02, K03, K04,       \
    K10, K11, K12, K13, K14,       \
    K20, K21, K22, K23, K24,       \
    K30, K31, K32, K33, K34,       \
    K40, K41, K42, K43, K44)       \
  {                                \
    {K00, K01, K02, K03, K04},     \
        {K10, K11, K12, K13, K14}, \
        {K20, K21, K22, K23, K24}, \
        {K30, K31, K32, K33, K34}, \
    {                              \
      K40, K41, K42, K43, K44      \
    }                              \
  }

#define LAYOUT LAYOUT_ortho_5x5

#endif /* BLE_MICRO_PRO */

#endif /* ATTACK25_BLE_H_ */