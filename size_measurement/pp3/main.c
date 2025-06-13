


volatile int aaa = 0;
volatile int aba = 0;
volatile int aca = 0;
volatile int aab = 0;
volatile int abb = 0;
volatile int acb = 0;
volatile int aac = 0;
volatile int abc = 0;
volatile int acc = 0;

volatile int baa = 0;
volatile int bba = 0;
volatile int bca = 0;
volatile int bab = 0;
volatile int bbb = 0;
volatile int bcb = 0;
volatile int bac = 0;
volatile int bbc = 0;
volatile int bcc = 0;

volatile int caa = 0;
volatile int cba = 0;
volatile int cca = 0;
volatile int cab = 0;
volatile int cbb = 0;
volatile int ccb = 0;
volatile int cac = 0;
volatile int cbc = 0;
volatile int ccc = 0;

struct ObjA{};
struct ObjB{};
struct ObjC{};
struct Object{}< struct ObjA; struct ObjB; struct ObjC; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2, struct Object* f3>() {  }

void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjA* f2, struct Object.ObjA* f3>() { aaa++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjA* f2, struct Object.ObjB* f3>() { aab++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjA* f2, struct Object.ObjC* f3>() { aac++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjB* f2, struct Object.ObjA* f3>() { aba++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjB* f2, struct Object.ObjB* f3>() { abb++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjB* f2, struct Object.ObjC* f3>() { abc++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjC* f2, struct Object.ObjA* f3>() { aca++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjC* f2, struct Object.ObjB* f3>() { acb++; }
void MultiMethodCollide<struct Object.ObjA* f1, struct Object.ObjC* f2, struct Object.ObjC* f3>() { acc++; }

void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjA* f2, struct Object.ObjA* f3>() { baa++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjA* f2, struct Object.ObjB* f3>() { bab++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjA* f2, struct Object.ObjC* f3>() { bac++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjB* f2, struct Object.ObjA* f3>() { bba++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjB* f2, struct Object.ObjB* f3>() { bbb++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjB* f2, struct Object.ObjC* f3>() { bbc++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjC* f2, struct Object.ObjA* f3>() { bca++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjC* f2, struct Object.ObjB* f3>() { bcb++; }
void MultiMethodCollide<struct Object.ObjB* f1, struct Object.ObjC* f2, struct Object.ObjC* f3>() { bcc++; }

void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjA* f2, struct Object.ObjA* f3>() { caa++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjA* f2, struct Object.ObjB* f3>() { cab++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjA* f2, struct Object.ObjC* f3>() { cac++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjB* f2, struct Object.ObjA* f3>() { cba++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjB* f2, struct Object.ObjB* f3>() { cbb++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjB* f2, struct Object.ObjC* f3>() { cbc++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjC* f2, struct Object.ObjA* f3>() { cca++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjC* f2, struct Object.ObjB* f3>() { ccb++; }
void MultiMethodCollide<struct Object.ObjC* f1, struct Object.ObjC* f2, struct Object.ObjC* f3>() { ccc++; }