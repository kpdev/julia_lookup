


volatile int collide_sa = 0;
volatile int collide_ss = 0;
volatile int collide_as = 0;
volatile int collide_aa = 0;


struct Spaceship{};
struct Asteroid{};
struct Object{}< struct Spaceship; struct Asteroid; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>() {  }
void MultiMethodCollide<struct Object.Spaceship* f1, struct Object.Asteroid* f2>() { collide_sa++; }
void MultiMethodCollide<struct Object.Spaceship* f1, struct Object.Spaceship* f2>() { collide_ss++; }
void MultiMethodCollide<struct Object.Asteroid* f1, struct Object.Spaceship* f2>() { collide_as++; }
void MultiMethodCollide<struct Object.Asteroid* f1, struct Object.Asteroid* f2>() { collide_aa++; }

