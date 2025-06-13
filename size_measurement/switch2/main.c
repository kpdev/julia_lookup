


volatile int aa = 0;
volatile int ab = 0;
volatile int ba = 0;
volatile int bb = 0;

typedef enum {
    TYPE_A,
    TYPE_B
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

void handle_aa(ObjA* o1, ObjA* o2) { aa++; }
void handle_ab(ObjA* o1, ObjB* o2) { ab++; }
void handle_ba(ObjB* o1, ObjA* o2) { ba++; }
void handle_bb(ObjB* o1, ObjB* o2) { bb++; }

void CollideSwitch(ObjBase *s1, ObjBase *s2) {
    switch(s1->type) {
        case TYPE_A: {
            ObjA *c1 = (ObjA *)s1;
            switch(s2->type) {
                case TYPE_A: handle_aa(c1, (ObjA *)s2); break;
                case TYPE_B: handle_ab(c1, (ObjB *)s2); break;
            }
            break;
        }
        
        case TYPE_B: {
            ObjB *r1 = (ObjB *)s1;
            switch(s2->type) {
                case TYPE_A: handle_ba(r1, (ObjA *)s2); break;
                case TYPE_B: handle_bb(r1, (ObjB *)s2); break;
            }
            break;
        }
    }
}