


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

typedef enum {
    TYPE_A,
    TYPE_B,
    TYPE_C,
    TYPE_D
} ObjType;

typedef struct ObjBase {
    ObjType type;
} ObjBase;

typedef struct ObjA{
    ObjBase base;
} ObjA;

typedef struct ObjB{
    ObjBase base;
} ObjB;

typedef struct ObjC{
    ObjBase base;
} ObjC;

typedef struct ObjD{
    ObjBase base;
} ObjD;

void handle_aa(ObjA* o1, ObjA* o2) { aa++; }
void handle_ab(ObjA* o1, ObjB* o2) { ab++; }
void handle_ac(ObjA* o1, ObjC* o2) { ac++; }
void handle_ad(ObjA* o1, ObjD* o2) { ad++; }

void handle_ba(ObjB* o1, ObjA* o2) { ba++; }
void handle_bb(ObjB* o1, ObjB* o2) { bb++; }
void handle_bc(ObjB* o1, ObjC* o2) { bc++; }
void handle_bd(ObjB* o1, ObjD* o2) { bd++; }

void handle_ca(ObjC* o1, ObjA* o2) { ca++; }
void handle_cb(ObjC* o1, ObjB* o2) { cb++; }
void handle_cc(ObjC* o1, ObjC* o2) { cc++; }
void handle_cd(ObjC* o1, ObjD* o2) { cd++; }

void handle_da(ObjD* o1, ObjA* o2) { da++; }
void handle_db(ObjD* o1, ObjB* o2) { db++; }
void handle_dc(ObjD* o1, ObjC* o2) { dc++; }
void handle_dd(ObjD* o1, ObjD* o2) { dd++; }



void CollideSwitch(ObjBase *s1, ObjBase *s2) {
    switch(s1->type) {
        case TYPE_A: {
            ObjA *o1 = (ObjA *)s1;
            switch(s2->type) {
                case TYPE_A: handle_aa(o1, (ObjA *)s2); break;
                case TYPE_B: handle_ab(o1, (ObjB *)s2); break;
                case TYPE_C: handle_ac(o1, (ObjC *)s2); break;
                case TYPE_D: handle_ad(o1, (ObjD *)s2); break;
            }
            break;
        }
        
        case TYPE_B: {
            ObjB *o1 = (ObjB *)s1;
            switch(s2->type) {
                case TYPE_A: handle_ba(o1, (ObjA *)s2); break;
                case TYPE_B: handle_bb(o1, (ObjB *)s2); break;
                case TYPE_C: handle_bc(o1, (ObjC *)s2); break;
                case TYPE_D: handle_bd(o1, (ObjD *)s2); break;
            }
            break;
        }

        case TYPE_C: {
            ObjC *o1 = (ObjC *)s1;
            switch(s2->type) {
                case TYPE_A: handle_ca(o1, (ObjA *)s2); break;
                case TYPE_B: handle_cb(o1, (ObjB *)s2); break;
                case TYPE_C: handle_cc(o1, (ObjC *)s2); break;
                case TYPE_D: handle_cd(o1, (ObjD *)s2); break;
            }
            break;
        }

        case TYPE_D: {
            ObjD *o1 = (ObjD *)s1;
            switch(s2->type) {
                case TYPE_A: handle_da(o1, (ObjA *)s2); break;
                case TYPE_B: handle_db(o1, (ObjB *)s2); break;
                case TYPE_C: handle_dc(o1, (ObjC *)s2); break;
                case TYPE_D: handle_dd(o1, (ObjD *)s2); break;
            }
            break;
        }

    }
}