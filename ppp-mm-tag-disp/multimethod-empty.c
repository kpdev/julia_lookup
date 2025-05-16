#include "multimethod-empty.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"

// -----------------------------------------------------------------------------
// For benchmarks
void MultimethodEmpty<struct Figure* f1>(Figure* f2) {}

volatile int empty_r_def = 0, empty_rr = 0, empty_tr = 0,
             empty_t_def = 0, empty_rt = 0, empty_tt = 0;
//-----------------------------------------------------------------------------
void MultimethodEmptyFirstRect<struct Figure* f1>(struct Figure.rect* r1) { empty_r_def++; }

void MultimethodEmptyFirstRect<struct Figure.rect* f1>(struct Figure.rect* r1) { empty_rr++; }
void MultimethodEmptyFirstRect<struct Figure.trian* f1>(struct Figure.rect* r1) { empty_tr++; }

//--------------------------------------------------------------------
void MultimethodEmptyFirstTrian<struct Figure* f1>(struct Figure.trian* r1) { empty_t_def++; }

void MultimethodEmptyFirstTrian<struct Figure.rect* f1>(struct Figure.trian* r1) { empty_rt++; }
void MultimethodEmptyFirstTrian<struct Figure.trian* f1>(struct Figure.trian* r1) { empty_tt++; }

// -----------------------------------------------------------------------------
// Specializations for benchmarks
void MultimethodEmpty<struct Figure.rect* r1>(Figure* f2) {
    MultimethodEmptyFirstRect<f2>(r1);
}

void MultimethodEmpty<struct Figure.trian* t1>(Figure* f2) {
    MultimethodEmptyFirstTrian<f2>(t1);
}

void MultimethodEmpty_Empty(struct Figure*, struct Figure*)
{}
