


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

struct Obj_a{};
struct Obj_b{};
struct Obj_c{};
struct Obj_d{};
struct Obj_e{};
struct Obj_f{};
struct Obj_g{};
struct Obj_h{};
struct Obj_i{};
struct Obj_j{};
struct Object{}< 
    struct Obj_a; struct Obj_b; 
    struct Obj_c; struct Obj_d;
    struct Obj_e; struct Obj_f;
    struct Obj_g; struct Obj_h;
    struct Obj_i; struct Obj_j; >;

void MultiMethodCollide<struct Object* f1, struct Object* f2>() {  }

void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_a* f2>() { var_aa++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_b* f2>() { var_ab++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_c* f2>() { var_ac++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_d* f2>() { var_ad++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_e* f2>() { var_ae++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_f* f2>() { var_af++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_g* f2>() { var_ag++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_h* f2>() { var_ah++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_i* f2>() { var_ai++; }
void MultiMethodCollide<struct Object.Obj_a* f1, struct Object.Obj_j* f2>() { var_aj++; }

void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_a* f2>() { var_ba++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_b* f2>() { var_bb++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_c* f2>() { var_bc++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_d* f2>() { var_bd++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_e* f2>() { var_be++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_f* f2>() { var_bf++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_g* f2>() { var_bg++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_h* f2>() { var_bh++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_i* f2>() { var_bi++; }
void MultiMethodCollide<struct Object.Obj_b* f1, struct Object.Obj_j* f2>() { var_bj++; }

void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_a* f2>() { var_ca++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_b* f2>() { var_cb++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_c* f2>() { var_cc++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_d* f2>() { var_cd++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_e* f2>() { var_ce++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_f* f2>() { var_cf++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_g* f2>() { var_cg++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_h* f2>() { var_ch++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_i* f2>() { var_ci++; }
void MultiMethodCollide<struct Object.Obj_c* f1, struct Object.Obj_j* f2>() { var_cj++; }

void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_a* f2>() { var_da++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_b* f2>() { var_db++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_c* f2>() { var_dc++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_d* f2>() { var_dd++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_e* f2>() { var_de++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_f* f2>() { var_df++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_g* f2>() { var_dg++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_h* f2>() { var_dh++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_i* f2>() { var_di++; }
void MultiMethodCollide<struct Object.Obj_d* f1, struct Object.Obj_j* f2>() { var_dj++; }

void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_a* f2>() { var_ea++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_b* f2>() { var_eb++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_c* f2>() { var_ec++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_d* f2>() { var_ed++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_e* f2>() { var_ee++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_f* f2>() { var_ef++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_g* f2>() { var_eg++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_h* f2>() { var_eh++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_i* f2>() { var_ei++; }
void MultiMethodCollide<struct Object.Obj_e* f1, struct Object.Obj_j* f2>() { var_ej++; }

void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_a* f2>() { var_fa++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_b* f2>() { var_fb++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_c* f2>() { var_fc++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_d* f2>() { var_fd++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_e* f2>() { var_fe++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_f* f2>() { var_ff++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_g* f2>() { var_fg++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_h* f2>() { var_fh++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_i* f2>() { var_fi++; }
void MultiMethodCollide<struct Object.Obj_f* f1, struct Object.Obj_j* f2>() { var_fj++; }

void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_a* f2>() { var_ga++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_b* f2>() { var_gb++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_c* f2>() { var_gc++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_d* f2>() { var_gd++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_e* f2>() { var_ge++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_f* f2>() { var_gf++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_g* f2>() { var_gg++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_h* f2>() { var_gh++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_i* f2>() { var_gi++; }
void MultiMethodCollide<struct Object.Obj_g* f1, struct Object.Obj_j* f2>() { var_gj++; }

void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_a* f2>() { var_ha++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_b* f2>() { var_hb++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_c* f2>() { var_hc++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_d* f2>() { var_hd++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_e* f2>() { var_he++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_f* f2>() { var_hf++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_g* f2>() { var_hg++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_h* f2>() { var_hh++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_i* f2>() { var_hi++; }
void MultiMethodCollide<struct Object.Obj_h* f1, struct Object.Obj_j* f2>() { var_hj++; }

void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_a* f2>() { var_ia++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_b* f2>() { var_ib++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_c* f2>() { var_ic++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_d* f2>() { var_id++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_e* f2>() { var_ie++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_f* f2>() { var_if++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_g* f2>() { var_ig++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_h* f2>() { var_ih++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_i* f2>() { var_ii++; }
void MultiMethodCollide<struct Object.Obj_i* f1, struct Object.Obj_j* f2>() { var_ij++; }

void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_a* f2>() { var_ja++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_b* f2>() { var_jb++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_c* f2>() { var_jc++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_d* f2>() { var_jd++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_e* f2>() { var_je++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_f* f2>() { var_jf++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_g* f2>() { var_jg++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_h* f2>() { var_jh++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_i* f2>() { var_ji++; }
void MultiMethodCollide<struct Object.Obj_j* f1, struct Object.Obj_j* f2>() { var_jj++; }
