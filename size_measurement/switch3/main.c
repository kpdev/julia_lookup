
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

typedef enum {
    TYPE_A,
    TYPE_B,
    TYPE_C
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


void handle_aaa(ObjA* o1, ObjA* o2, ObjA* o3) { aaa++; }
void handle_aab(ObjA* o1, ObjA* o2, ObjB* o3) { aab++; }
void handle_aac(ObjA* o1, ObjA* o2, ObjC* o3) { aac++; }
void handle_aba(ObjA* o1, ObjB* o2, ObjA* o3) { aba++; }
void handle_abb(ObjA* o1, ObjB* o2, ObjB* o3) { abb++; }
void handle_abc(ObjA* o1, ObjB* o2, ObjC* o3) { abc++; }
void handle_aca(ObjA* o1, ObjC* o2, ObjA* o3) { aca++; }
void handle_acb(ObjA* o1, ObjC* o2, ObjB* o3) { acb++; }
void handle_acc(ObjA* o1, ObjC* o2, ObjC* o3) { acc++; }

void handle_baa(ObjB* o1, ObjA* o2, ObjA* o3) { baa++; }
void handle_bab(ObjB* o1, ObjA* o2, ObjB* o3) { bab++; }
void handle_bac(ObjB* o1, ObjA* o2, ObjC* o3) { bac++; }
void handle_bba(ObjB* o1, ObjB* o2, ObjA* o3) { bba++; }
void handle_bbb(ObjB* o1, ObjB* o2, ObjB* o3) { bbb++; }
void handle_bbc(ObjB* o1, ObjB* o2, ObjC* o3) { bbc++; }
void handle_bca(ObjB* o1, ObjC* o2, ObjA* o3) { bca++; }
void handle_bcb(ObjB* o1, ObjC* o2, ObjB* o3) { bcb++; }
void handle_bcc(ObjB* o1, ObjC* o2, ObjC* o3) { bcc++; }

void handle_caa(ObjC* o1, ObjA* o2, ObjA* o3) { caa++; }
void handle_cab(ObjC* o1, ObjA* o2, ObjB* o3) { cab++; }
void handle_cac(ObjC* o1, ObjA* o2, ObjC* o3) { cac++; }
void handle_cba(ObjC* o1, ObjB* o2, ObjA* o3) { cba++; }
void handle_cbb(ObjC* o1, ObjB* o2, ObjB* o3) { cbb++; }
void handle_cbc(ObjC* o1, ObjB* o2, ObjC* o3) { cbc++; }
void handle_cca(ObjC* o1, ObjC* o2, ObjA* o3) { cca++; }
void handle_ccb(ObjC* o1, ObjC* o2, ObjB* o3) { ccb++; }
void handle_ccc(ObjC* o1, ObjC* o2, ObjC* o3) { ccc++; }

void CollideSwitch(ObjBase *s1, ObjBase *s2, ObjBase *s3) {
    switch(s1->type) {
        case TYPE_A: {
            switch(s2->type) {
                case TYPE_A: {
                    switch(s3->type) {
                        case TYPE_A: handle_aaa((ObjA*)s1, (ObjA*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_aab((ObjA*)s1, (ObjA*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_aac((ObjA*)s1, (ObjA*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_B: {
                    switch(s3->type) {
                        case TYPE_A: handle_aba((ObjA*)s1, (ObjB*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_abb((ObjA*)s1, (ObjB*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_abc((ObjA*)s1, (ObjB*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_C: {
                    switch(s3->type) {
                        case TYPE_A: handle_aca((ObjA*)s1, (ObjC*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_acb((ObjA*)s1, (ObjC*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_acc((ObjA*)s1, (ObjC*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
            }
            break;
        }


        case TYPE_B: {
            switch(s2->type) {
                case TYPE_A: {
                    switch(s3->type) {
                        case TYPE_A: handle_baa((ObjB*)s1, (ObjA*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_bab((ObjB*)s1, (ObjA*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_bac((ObjB*)s1, (ObjA*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_B: {
                    switch(s3->type) {
                        case TYPE_A: handle_bba((ObjB*)s1, (ObjB*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_bbb((ObjB*)s1, (ObjB*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_bbc((ObjB*)s1, (ObjB*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_C: {
                    switch(s3->type) {
                        case TYPE_A: handle_bca((ObjB*)s1, (ObjC*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_bcb((ObjB*)s1, (ObjC*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_bcc((ObjB*)s1, (ObjC*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
            }
            break;
        }

        case TYPE_C: {
            switch(s2->type) {
                case TYPE_A: {
                    switch(s3->type) {
                        case TYPE_A: handle_caa((ObjC*)s1, (ObjA*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_cab((ObjC*)s1, (ObjA*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_cac((ObjC*)s1, (ObjA*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_B: {
                    switch(s3->type) {
                        case TYPE_A: handle_cba((ObjC*)s1, (ObjB*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_cbb((ObjC*)s1, (ObjB*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_cbc((ObjC*)s1, (ObjB*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
                case TYPE_C: {
                    switch(s3->type) {
                        case TYPE_A: handle_cca((ObjC*)s1, (ObjC*)s2, (ObjA*)s3); break;
                        case TYPE_B: handle_ccb((ObjC*)s1, (ObjC*)s2, (ObjB*)s3); break;
                        case TYPE_C: handle_ccc((ObjC*)s1, (ObjC*)s2, (ObjC*)s3); break;
                    }
                } 
                break;
            }
            break;
        }
    }
}