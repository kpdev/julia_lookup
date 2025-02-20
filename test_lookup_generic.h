#include "julia.h"
#include "ppp-mm-tag-disp/figure-rectangle.h"
#include "ppp-mm-tag-disp/figure-triangle.h"
#include "ppp-mm-tag-disp/multimethod-empty.h"

struct _jl_value_t
{

};


void create_test_args(jl_value_t ***args, uint32_t nargs);

void init_mock_data_for_test();


struct Spaceship{};
struct Asteroid{};
struct Object{}< struct Spaceship; struct Asteroid; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>();

struct Figure* get_figure(int i);

struct Object* get_space_object(int i);
