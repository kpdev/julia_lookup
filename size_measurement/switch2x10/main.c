


volatile int var_aa = 0;
volatile int var_ab = 0;
volatile int var_ac = 0;
volatile int var_ad = 0;
volatile int var_ae = 0;
volatile int var_af = 0;
volatile int var_ag = 0;
volatile int var_ah = 0;
volatile int var_ai = 0;
volatile int var_aj = 0;
volatile int var_ba = 0;
volatile int var_bb = 0;
volatile int var_bc = 0;
volatile int var_bd = 0;
volatile int var_be = 0;
volatile int var_bf = 0;
volatile int var_bg = 0;
volatile int var_bh = 0;
volatile int var_bi = 0;
volatile int var_bj = 0;
volatile int var_ca = 0;
volatile int var_cb = 0;
volatile int var_cc = 0;
volatile int var_cd = 0;
volatile int var_ce = 0;
volatile int var_cf = 0;
volatile int var_cg = 0;
volatile int var_ch = 0;
volatile int var_ci = 0;
volatile int var_cj = 0;
volatile int var_da = 0;
volatile int var_db = 0;
volatile int var_dc = 0;
volatile int var_dd = 0;
volatile int var_de = 0;
volatile int var_df = 0;
volatile int var_dg = 0;
volatile int var_dh = 0;
volatile int var_di = 0;
volatile int var_dj = 0;
volatile int var_ea = 0;
volatile int var_eb = 0;
volatile int var_ec = 0;
volatile int var_ed = 0;
volatile int var_ee = 0;
volatile int var_ef = 0;
volatile int var_eg = 0;
volatile int var_eh = 0;
volatile int var_ei = 0;
volatile int var_ej = 0;
volatile int var_fa = 0;
volatile int var_fb = 0;
volatile int var_fc = 0;
volatile int var_fd = 0;
volatile int var_fe = 0;
volatile int var_ff = 0;
volatile int var_fg = 0;
volatile int var_fh = 0;
volatile int var_fi = 0;
volatile int var_fj = 0;
volatile int var_ga = 0;
volatile int var_gb = 0;
volatile int var_gc = 0;
volatile int var_gd = 0;
volatile int var_ge = 0;
volatile int var_gf = 0;
volatile int var_gg = 0;
volatile int var_gh = 0;
volatile int var_gi = 0;
volatile int var_gj = 0;
volatile int var_ha = 0;
volatile int var_hb = 0;
volatile int var_hc = 0;
volatile int var_hd = 0;
volatile int var_he = 0;
volatile int var_hf = 0;
volatile int var_hg = 0;
volatile int var_hh = 0;
volatile int var_hi = 0;
volatile int var_hj = 0;
volatile int var_ia = 0;
volatile int var_ib = 0;
volatile int var_ic = 0;
volatile int var_id = 0;
volatile int var_ie = 0;
volatile int var_if = 0;
volatile int var_ig = 0;
volatile int var_ih = 0;
volatile int var_ii = 0;
volatile int var_ij = 0;
volatile int var_ja = 0;
volatile int var_jb = 0;
volatile int var_jc = 0;
volatile int var_jd = 0;
volatile int var_je = 0;
volatile int var_jf = 0;
volatile int var_jg = 0;
volatile int var_jh = 0;
volatile int var_ji = 0;
volatile int var_jj = 0;

typedef enum {
    TYPE_A,
    TYPE_B,
    TYPE_C,
    TYPE_D,
    TYPE_E,
    TYPE_F,
    TYPE_G,
    TYPE_H,
    TYPE_I,
    TYPE_J
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

typedef struct ObjE{
    ObjBase base;
} ObjE;

typedef struct ObjF{
    ObjBase base;
} ObjF;

typedef struct ObjG{
    ObjBase base;
} ObjG;

typedef struct ObjH{
    ObjBase base;
} ObjH;

typedef struct ObjI{
    ObjBase base;
} ObjI;

typedef struct ObjJ{
    ObjBase base;
} ObjJ;

void handle_aa(ObjA* o1, ObjA* o2) { var_aa++; }
void handle_ab(ObjA* o1, ObjB* o2) { var_ab++; }
void handle_ac(ObjA* o1, ObjC* o2) { var_ac++; }
void handle_ad(ObjA* o1, ObjD* o2) { var_ad++; }
void handle_ae(ObjA* o1, ObjE* o2) { var_ae++; }
void handle_af(ObjA* o1, ObjF* o2) { var_af++; }
void handle_ag(ObjA* o1, ObjG* o2) { var_ag++; }
void handle_ah(ObjA* o1, ObjH* o2) { var_ah++; }
void handle_ai(ObjA* o1, ObjI* o2) { var_ai++; }
void handle_aj(ObjA* o1, ObjJ* o2) { var_aj++; }

void handle_ba(ObjB* o1, ObjA* o2) { var_ba++; }
void handle_bb(ObjB* o1, ObjB* o2) { var_bb++; }
void handle_bc(ObjB* o1, ObjC* o2) { var_bc++; }
void handle_bd(ObjB* o1, ObjD* o2) { var_bd++; }
void handle_be(ObjB* o1, ObjE* o2) { var_be++; }
void handle_bf(ObjB* o1, ObjF* o2) { var_bf++; }
void handle_bg(ObjB* o1, ObjG* o2) { var_bg++; }
void handle_bh(ObjB* o1, ObjH* o2) { var_bh++; }
void handle_bi(ObjB* o1, ObjI* o2) { var_bi++; }
void handle_bj(ObjB* o1, ObjJ* o2) { var_bj++; }

void handle_ca(ObjC* o1, ObjA* o2) { var_ca++; }
void handle_cb(ObjC* o1, ObjB* o2) { var_cb++; }
void handle_cc(ObjC* o1, ObjC* o2) { var_cc++; }
void handle_cd(ObjC* o1, ObjD* o2) { var_cd++; }
void handle_ce(ObjC* o1, ObjE* o2) { var_ce++; }
void handle_cf(ObjC* o1, ObjF* o2) { var_cf++; }
void handle_cg(ObjC* o1, ObjG* o2) { var_cg++; }
void handle_ch(ObjC* o1, ObjH* o2) { var_ch++; }
void handle_ci(ObjC* o1, ObjI* o2) { var_ci++; }
void handle_cj(ObjC* o1, ObjJ* o2) { var_cj++; }

void handle_da(ObjD* o1, ObjA* o2) { var_da++; }
void handle_db(ObjD* o1, ObjB* o2) { var_db++; }
void handle_dc(ObjD* o1, ObjC* o2) { var_dc++; }
void handle_dd(ObjD* o1, ObjD* o2) { var_dd++; }
void handle_de(ObjD* o1, ObjE* o2) { var_de++; }
void handle_df(ObjD* o1, ObjF* o2) { var_df++; }
void handle_dg(ObjD* o1, ObjG* o2) { var_dg++; }
void handle_dh(ObjD* o1, ObjH* o2) { var_dh++; }
void handle_di(ObjD* o1, ObjI* o2) { var_di++; }
void handle_dj(ObjD* o1, ObjJ* o2) { var_dj++; }

void handle_ea(ObjE* o1, ObjA* o2) { var_ea++; }
void handle_eb(ObjE* o1, ObjB* o2) { var_eb++; }
void handle_ec(ObjE* o1, ObjC* o2) { var_ec++; }
void handle_ed(ObjE* o1, ObjD* o2) { var_ed++; }
void handle_ee(ObjE* o1, ObjE* o2) { var_ee++; }
void handle_ef(ObjE* o1, ObjF* o2) { var_ef++; }
void handle_eg(ObjE* o1, ObjG* o2) { var_eg++; }
void handle_eh(ObjE* o1, ObjH* o2) { var_eh++; }
void handle_ei(ObjE* o1, ObjI* o2) { var_ei++; }
void handle_ej(ObjE* o1, ObjJ* o2) { var_ej++; }

void handle_fa(ObjF* o1, ObjA* o2) { var_fa++; }
void handle_fb(ObjF* o1, ObjB* o2) { var_fb++; }
void handle_fc(ObjF* o1, ObjC* o2) { var_fc++; }
void handle_fd(ObjF* o1, ObjD* o2) { var_fd++; }
void handle_fe(ObjF* o1, ObjE* o2) { var_fe++; }
void handle_ff(ObjF* o1, ObjF* o2) { var_ff++; }
void handle_fg(ObjF* o1, ObjG* o2) { var_fg++; }
void handle_fh(ObjF* o1, ObjH* o2) { var_fh++; }
void handle_fi(ObjF* o1, ObjI* o2) { var_fi++; }
void handle_fj(ObjF* o1, ObjJ* o2) { var_fj++; }

void handle_ga(ObjG* o1, ObjA* o2) { var_ga++; }
void handle_gb(ObjG* o1, ObjB* o2) { var_gb++; }
void handle_gc(ObjG* o1, ObjC* o2) { var_gc++; }
void handle_gd(ObjG* o1, ObjD* o2) { var_gd++; }
void handle_ge(ObjG* o1, ObjE* o2) { var_ge++; }
void handle_gf(ObjG* o1, ObjF* o2) { var_gf++; }
void handle_gg(ObjG* o1, ObjG* o2) { var_gg++; }
void handle_gh(ObjG* o1, ObjH* o2) { var_gh++; }
void handle_gi(ObjG* o1, ObjI* o2) { var_gi++; }
void handle_gj(ObjG* o1, ObjJ* o2) { var_gj++; }

void handle_ha(ObjH* o1, ObjA* o2) { var_ha++; }
void handle_hb(ObjH* o1, ObjB* o2) { var_hb++; }
void handle_hc(ObjH* o1, ObjC* o2) { var_hc++; }
void handle_hd(ObjH* o1, ObjD* o2) { var_hd++; }
void handle_he(ObjH* o1, ObjE* o2) { var_he++; }
void handle_hf(ObjH* o1, ObjF* o2) { var_hf++; }
void handle_hg(ObjH* o1, ObjG* o2) { var_hg++; }
void handle_hh(ObjH* o1, ObjH* o2) { var_hh++; }
void handle_hi(ObjH* o1, ObjI* o2) { var_hi++; }
void handle_hj(ObjH* o1, ObjJ* o2) { var_hj++; }

void handle_ia(ObjI* o1, ObjA* o2) { var_ia++; }
void handle_ib(ObjI* o1, ObjB* o2) { var_ib++; }
void handle_ic(ObjI* o1, ObjC* o2) { var_ic++; }
void handle_id(ObjI* o1, ObjD* o2) { var_id++; }
void handle_ie(ObjI* o1, ObjE* o2) { var_ie++; }
void handle_if(ObjI* o1, ObjF* o2) { var_if++; }
void handle_ig(ObjI* o1, ObjG* o2) { var_ig++; }
void handle_ih(ObjI* o1, ObjH* o2) { var_ih++; }
void handle_ii(ObjI* o1, ObjI* o2) { var_ii++; }
void handle_ij(ObjI* o1, ObjJ* o2) { var_ij++; }

void handle_ja(ObjJ* o1, ObjA* o2) { var_ja++; }
void handle_jb(ObjJ* o1, ObjB* o2) { var_jb++; }
void handle_jc(ObjJ* o1, ObjC* o2) { var_jc++; }
void handle_jd(ObjJ* o1, ObjD* o2) { var_jd++; }
void handle_je(ObjJ* o1, ObjE* o2) { var_je++; }
void handle_jf(ObjJ* o1, ObjF* o2) { var_jf++; }
void handle_jg(ObjJ* o1, ObjG* o2) { var_jg++; }
void handle_jh(ObjJ* o1, ObjH* o2) { var_jh++; }
void handle_ji(ObjJ* o1, ObjI* o2) { var_ji++; }
void handle_jj(ObjJ* o1, ObjJ* o2) { var_jj++; }


void CollideSwitch(ObjBase *s1, ObjBase *s2) {
    switch(s1->type) {
        case TYPE_A: {
            switch(s2->type) {
                case TYPE_A: handle_aa((ObjA *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_ab((ObjA *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_ac((ObjA *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_ad((ObjA *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_ae((ObjA *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_af((ObjA *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_ag((ObjA *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_ah((ObjA *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_ai((ObjA *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_aj((ObjA *)s1, (ObjJ *)s2); break;
            }
            break;
        }
        
        case TYPE_B: {
            switch(s2->type) {
                case TYPE_A: handle_ba((ObjB *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_bb((ObjB *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_bc((ObjB *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_bd((ObjB *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_be((ObjB *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_bf((ObjB *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_bg((ObjB *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_bh((ObjB *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_bi((ObjB *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_bj((ObjB *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_C: {
            switch(s2->type) {
                case TYPE_A: handle_ca((ObjC *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_cb((ObjC *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_cc((ObjC *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_cd((ObjC *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_ce((ObjC *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_cf((ObjC *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_cg((ObjC *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_ch((ObjC *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_ci((ObjC *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_cj((ObjC *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_D: {
            switch(s2->type) {
                case TYPE_A: handle_da((ObjD *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_db((ObjD *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_dc((ObjD *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_dd((ObjD *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_de((ObjD *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_df((ObjD *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_dg((ObjD *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_dh((ObjD *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_di((ObjD *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_dj((ObjD *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_E: {
            switch(s2->type) {
                case TYPE_A: handle_ea((ObjE *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_eb((ObjE *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_ec((ObjE *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_ed((ObjE *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_ee((ObjE *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_ef((ObjE *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_eg((ObjE *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_eh((ObjE *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_ei((ObjE *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_ej((ObjE *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_F: {
            switch(s2->type) {
                case TYPE_A: handle_fa((ObjF *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_fb((ObjF *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_fc((ObjF *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_fd((ObjF *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_fe((ObjF *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_ff((ObjF *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_fg((ObjF *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_fh((ObjF *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_fi((ObjF *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_fj((ObjF *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_G: {
            switch(s2->type) {
                case TYPE_A: handle_ga((ObjG *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_gb((ObjG *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_gc((ObjG *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_gd((ObjG *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_ge((ObjG *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_gf((ObjG *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_gg((ObjG *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_gh((ObjG *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_gi((ObjG *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_gj((ObjG *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_H: {
            switch(s2->type) {
                case TYPE_A: handle_ha((ObjH *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_hb((ObjH *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_hc((ObjH *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_hd((ObjH *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_he((ObjH *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_hf((ObjH *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_hg((ObjH *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_hh((ObjH *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_hi((ObjH *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_hj((ObjH *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_I: {
            switch(s2->type) {
                case TYPE_A: handle_ia((ObjI *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_ib((ObjI *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_ic((ObjI *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_id((ObjI *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_ie((ObjI *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_if((ObjI *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_ig((ObjI *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_ih((ObjI *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_ii((ObjI *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_ij((ObjI *)s1, (ObjJ *)s2); break;
            }
            break;
        }

        case TYPE_J: {
            switch(s2->type) {
                case TYPE_A: handle_ja((ObjJ *)s1, (ObjA *)s2); break;
                case TYPE_B: handle_jb((ObjJ *)s1, (ObjB *)s2); break;
                case TYPE_C: handle_jc((ObjJ *)s1, (ObjC *)s2); break;
                case TYPE_D: handle_jd((ObjJ *)s1, (ObjD *)s2); break;
                case TYPE_E: handle_je((ObjJ *)s1, (ObjE *)s2); break;
                case TYPE_F: handle_jf((ObjJ *)s1, (ObjF *)s2); break;
                case TYPE_G: handle_jg((ObjJ *)s1, (ObjG *)s2); break;
                case TYPE_H: handle_jh((ObjJ *)s1, (ObjH *)s2); break;
                case TYPE_I: handle_ji((ObjJ *)s1, (ObjI *)s2); break;
                case TYPE_J: handle_jj((ObjJ *)s1, (ObjJ *)s2); break;
            }
            break;
        }
    }
}