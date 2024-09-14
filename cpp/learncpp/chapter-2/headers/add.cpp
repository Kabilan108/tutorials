// we use this so errors can be caughtat compile time not link time
//
//header order:
// - The paired header file
// - Other headers from your project
// - 3rd party library headers
// - Standard library headers

// header (include) guard:
#ifndef ADD
#define ADD
// `#pragma once` alsodoes this; asks compiler to guard header

#include "add.h"

int add(int x, int y) {
  return x + y;
}

#endif

