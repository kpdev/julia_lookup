#include "multimethod-empty.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"

// -----------------------------------------------------------------------------
// For benchmarks
void MultimethodEmpty<struct Figure* f1>(Figure* f2) {}


//-----------------------------------------------------------------------------
void MultimethodEmptyFirstRect<struct Figure* f1>(struct Figure.rect* r1) {}

void MultimethodEmptyFirstRect<struct Figure.rect* f1>(struct Figure.rect* r1) {}
void MultimethodEmptyFirstRect<struct Figure.trian* f1>(struct Figure.rect* r1) {}

//--------------------------------------------------------------------
void MultimethodEmptyFirstTrian<struct Figure* f1>(struct Figure.trian* r1) {}

void MultimethodEmptyFirstTrian<struct Figure.rect* f1>(struct Figure.trian* r1) {}
void MultimethodEmptyFirstTrian<struct Figure.trian* f1>(struct Figure.trian* r1) {}

// -----------------------------------------------------------------------------
// Specializations for benchmarks
void MultimethodEmpty<struct Figure.rect* r1>(Figure* f2) {
    MultimethodEmptyFirstRect<f2>(r1);
}

void MultimethodEmpty<struct Figure.trian* t1>(Figure* f2) {
    MultimethodEmptyFirstTrian<f2>(t1);
}