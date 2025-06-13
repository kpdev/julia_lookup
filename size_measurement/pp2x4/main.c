


volatile int aa = 0;
volatile int ab = 0;
volatile int ac = 0;
volatile int ad = 0;

volatile int ba = 0;
volatile int bb = 0;
volatile int bc = 0;
volatile int bd = 0;

volatile int ca = 0;
volatile int cb = 0;
volatile int cc = 0;
volatile int cd = 0;

volatile int da = 0;
volatile int db = 0;
volatile int dc = 0;
volatile int dd = 0;

struct ObjA{};
struct ObjB{};
struct ObjC{};
struct ObjD{};
struct Object{}< struct ObjA; struct ObjB; struct ObjC; struct ObjD; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>() {  }

void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjA* f2>() { aa++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjB* f2>() { ab++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjC* f2>() { ac++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjD* f2>() { ad++; }

void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjA* f2>() { ba++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjB* f2>() { bb++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjC* f2>() { bc++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjD* f2>() { bd++; }

void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjA* f2>() { ca++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjB* f2>() { cb++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjC* f2>() { cc++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjD* f2>() { cd++; }

void MultiMethodCollide<struct Object.ObjD* f1, struct Object.ObjA* f2>() { da++; }
void MultiMethodCollide<struct Object.ObjD* f1, struct Object.ObjB* f2>() { db++; }
void MultiMethodCollide<struct Object.ObjD* f1, struct Object.ObjC* f2>() { dc++; }
void MultiMethodCollide<struct Object.ObjD* f1, struct Object.ObjD* f2>() { dd++; }