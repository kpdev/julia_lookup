#include "julia.h"

struct _jl_value_t
{

};


void create_test_args(jl_value_t ***args, uint32_t nargs);

void init_mock_data_for_test();


struct Spaceship{};
struct Asteroid{};
struct Object{}< struct Spaceship; struct Asteroid; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>();



