#include "julia.h"
#include "ppp-mm-tag-disp/figure-rectangle.h"
#include "ppp-mm-tag-disp/figure-triangle.h"
#include "ppp-mm-tag-disp/multimethod-empty.h"
#include "procedural-vt/proced.h"
#include "procedural-switch/proced-switch.h"

struct _jl_value_t
{

};


void create_test_args(jl_value_t ***args, uint32_t nargs);

void init_mock_data_for_test(int num_of_args);


struct Spaceship{};
struct Asteroid{};
struct Object{}< struct Spaceship; struct Asteroid; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>();
void MultiMethodCollide3D<struct Object* f1, struct Object* f2, struct Object* f3>();
void MultiMethodCollide5D<struct Object* f1,
                          struct Object* f2,
                          struct Object* f3,
                          struct Object* f4,
                          struct Object* f5>();

struct Figure* get_figure(int i);

struct Object* get_space_object(int i);
