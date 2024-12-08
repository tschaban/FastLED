
#include "./led_layout_array.h"
#include "./settings.h"

LedColumns LedCurtinArray() {
  static const int kLedRepeatTable[] = {
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22,
    22
  };
  const int* out = kLedRepeatTable;
  const int size = sizeof(kLedRepeatTable) / sizeof(*kLedRepeatTable);
  return LedColumns(out, size);
}

LedColumns LedLuminescentArray() {
  /////////////////////////////////////////////////////////
  // Repeat data for the LED piano.
  static const int kLedRepeatTable[] = {
    25,
    25,
    26,
    26,
    27,
    27,
    28,
    27,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    28,
    27,
    28,
    27,
    27,
    26,
    26,
    25,
    25,
    24,
    24,
    23,
    23,
    21,
    20,
    18,
    17,
    15,
    14,
    12,
    11,
    10,
    10,
    9,
    9,
    8,
    8,
    7,
    7,
    6,
    6,
    5,
    6,
    5,
    5,
    4,
    5,
    4,
    4,
    3,
    4,
    3,
    3,
    2,
    2,
    1
  };
  const int* out = kLedRepeatTable;
  const int size = sizeof(kLedRepeatTable) / sizeof(*kLedRepeatTable);
  return LedColumns(out, size);
}

LedColumns LedLayoutArray() {
  if (kUseLedCurtin) {
    return LedCurtinArray();
  } else {
  	return LedLuminescentArray();
  }
}