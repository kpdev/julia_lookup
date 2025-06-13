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

class Element_a;
class Element_b;
class Element_c;
class Element_d;
class Element_e;
class Element_f;
class Element_g;
class Element_h;
class Element_i;
class Element_j;


class Element {
public:
    virtual ~Element() = default;
    virtual void visit(class Element* visitor) = 0;
    virtual void visit(class Element_a& visitor) = 0;
    virtual void visit(class Element_b& visitor) = 0;
    virtual void visit(class Element_c& visitor) = 0;
    virtual void visit(class Element_d& visitor) = 0;
    virtual void visit(class Element_e& visitor) = 0;
    virtual void visit(class Element_f& visitor) = 0;
    virtual void visit(class Element_g& visitor) = 0;
    virtual void visit(class Element_h& visitor) = 0;
    virtual void visit(class Element_i& visitor) = 0;
    virtual void visit(class Element_j& visitor) = 0;
};
    
class Element_a : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_b : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_c : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_d : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_e : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_f : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_g : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_h : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};

class Element_i : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};


class Element_j : public Element {
public:
    virtual void visit(class Element* visitor) { visitor->visit(*this); };
    virtual void visit(class Element_a& visitor);
    virtual void visit(class Element_b& visitor);
    virtual void visit(class Element_c& visitor);
    virtual void visit(class Element_d& visitor);
    virtual void visit(class Element_e& visitor);
    virtual void visit(class Element_f& visitor);
    virtual void visit(class Element_g& visitor);
    virtual void visit(class Element_h& visitor);
    virtual void visit(class Element_i& visitor);
    virtual void visit(class Element_j& visitor);
};


class Element_a g_a;
class Element_b g_b;
class Element_c g_c;
class Element_d g_d;
class Element_e g_e;
class Element_f g_f;
class Element_g g_g;
class Element_h g_h;
class Element_i g_i;
class Element_j g_j;

void Element_a::visit(class Element_a& visitor) { var_aa++; }
void Element_a::visit(class Element_b& visitor) { var_ab++; }
void Element_a::visit(class Element_c& visitor) { var_ac++; }
void Element_a::visit(class Element_d& visitor) { var_ad++; }
void Element_a::visit(class Element_e& visitor) { var_ae++; }
void Element_a::visit(class Element_f& visitor) { var_af++; }
void Element_a::visit(class Element_g& visitor) { var_ag++; }
void Element_a::visit(class Element_h& visitor) { var_ah++; }
void Element_a::visit(class Element_i& visitor) { var_ai++; }
void Element_a::visit(class Element_j& visitor) { var_aj++; }

void Element_b::visit(class Element_a& visitor) { var_ba++; }
void Element_b::visit(class Element_b& visitor) { var_bb++; }
void Element_b::visit(class Element_c& visitor) { var_bc++; }
void Element_b::visit(class Element_d& visitor) { var_bd++; }
void Element_b::visit(class Element_e& visitor) { var_be++; }
void Element_b::visit(class Element_f& visitor) { var_bf++; }
void Element_b::visit(class Element_g& visitor) { var_bg++; }
void Element_b::visit(class Element_h& visitor) { var_bh++; }
void Element_b::visit(class Element_i& visitor) { var_bi++; }
void Element_b::visit(class Element_j& visitor) { var_bj++; }

void Element_c::visit(class Element_a& visitor) { var_ca++; }
void Element_c::visit(class Element_b& visitor) { var_cb++; }
void Element_c::visit(class Element_c& visitor) { var_cc++; }
void Element_c::visit(class Element_d& visitor) { var_cd++; }
void Element_c::visit(class Element_e& visitor) { var_ce++; }
void Element_c::visit(class Element_f& visitor) { var_cf++; }
void Element_c::visit(class Element_g& visitor) { var_cg++; }
void Element_c::visit(class Element_h& visitor) { var_ch++; }
void Element_c::visit(class Element_i& visitor) { var_ci++; }
void Element_c::visit(class Element_j& visitor) { var_cj++; }

void Element_d::visit(class Element_a& visitor) { var_da++; }
void Element_d::visit(class Element_b& visitor) { var_db++; }
void Element_d::visit(class Element_c& visitor) { var_dc++; }
void Element_d::visit(class Element_d& visitor) { var_dd++; }
void Element_d::visit(class Element_e& visitor) { var_de++; }
void Element_d::visit(class Element_f& visitor) { var_df++; }
void Element_d::visit(class Element_g& visitor) { var_dg++; }
void Element_d::visit(class Element_h& visitor) { var_dh++; }
void Element_d::visit(class Element_i& visitor) { var_di++; }
void Element_d::visit(class Element_j& visitor) { var_dj++; }

void Element_e::visit(class Element_a& visitor) { var_ea++; }
void Element_e::visit(class Element_b& visitor) { var_eb++; }
void Element_e::visit(class Element_c& visitor) { var_ec++; }
void Element_e::visit(class Element_d& visitor) { var_ed++; }
void Element_e::visit(class Element_e& visitor) { var_ee++; }
void Element_e::visit(class Element_f& visitor) { var_ef++; }
void Element_e::visit(class Element_g& visitor) { var_eg++; }
void Element_e::visit(class Element_h& visitor) { var_eh++; }
void Element_e::visit(class Element_i& visitor) { var_ei++; }
void Element_e::visit(class Element_j& visitor) { var_ej++; }

void Element_f::visit(class Element_a& visitor) { var_fa++; }
void Element_f::visit(class Element_b& visitor) { var_fb++; }
void Element_f::visit(class Element_c& visitor) { var_fc++; }
void Element_f::visit(class Element_d& visitor) { var_fd++; }
void Element_f::visit(class Element_e& visitor) { var_fe++; }
void Element_f::visit(class Element_f& visitor) { var_ff++; }
void Element_f::visit(class Element_g& visitor) { var_fg++; }
void Element_f::visit(class Element_h& visitor) { var_fh++; }
void Element_f::visit(class Element_i& visitor) { var_fi++; }
void Element_f::visit(class Element_j& visitor) { var_fj++; }

void Element_g::visit(class Element_a& visitor) { var_ga++; }
void Element_g::visit(class Element_b& visitor) { var_gb++; }
void Element_g::visit(class Element_c& visitor) { var_gc++; }
void Element_g::visit(class Element_d& visitor) { var_gd++; }
void Element_g::visit(class Element_e& visitor) { var_ge++; }
void Element_g::visit(class Element_f& visitor) { var_gf++; }
void Element_g::visit(class Element_g& visitor) { var_gg++; }
void Element_g::visit(class Element_h& visitor) { var_gh++; }
void Element_g::visit(class Element_i& visitor) { var_gi++; }
void Element_g::visit(class Element_j& visitor) { var_gj++; }

void Element_h::visit(class Element_a& visitor) { var_ha++; }
void Element_h::visit(class Element_b& visitor) { var_hb++; }
void Element_h::visit(class Element_c& visitor) { var_hc++; }
void Element_h::visit(class Element_d& visitor) { var_hd++; }
void Element_h::visit(class Element_e& visitor) { var_he++; }
void Element_h::visit(class Element_f& visitor) { var_hf++; }
void Element_h::visit(class Element_g& visitor) { var_hg++; }
void Element_h::visit(class Element_h& visitor) { var_hh++; }
void Element_h::visit(class Element_i& visitor) { var_hi++; }
void Element_h::visit(class Element_j& visitor) { var_hj++; }

void Element_i::visit(class Element_a& visitor) { var_ia++; }
void Element_i::visit(class Element_b& visitor) { var_ib++; }
void Element_i::visit(class Element_c& visitor) { var_ic++; }
void Element_i::visit(class Element_d& visitor) { var_id++; }
void Element_i::visit(class Element_e& visitor) { var_ie++; }
void Element_i::visit(class Element_f& visitor) { var_if++; }
void Element_i::visit(class Element_g& visitor) { var_ig++; }
void Element_i::visit(class Element_h& visitor) { var_ih++; }
void Element_i::visit(class Element_i& visitor) { var_ii++; }
void Element_i::visit(class Element_j& visitor) { var_ij++; }

void Element_j::visit(class Element_a& visitor) { var_ja++; }
void Element_j::visit(class Element_b& visitor) { var_jb++; }
void Element_j::visit(class Element_c& visitor) { var_jc++; }
void Element_j::visit(class Element_d& visitor) { var_jd++; }
void Element_j::visit(class Element_e& visitor) { var_je++; }
void Element_j::visit(class Element_f& visitor) { var_jf++; }
void Element_j::visit(class Element_g& visitor) { var_jg++; }
void Element_j::visit(class Element_h& visitor) { var_jh++; }
void Element_j::visit(class Element_i& visitor) { var_ji++; }
void Element_j::visit(class Element_j& visitor) { var_jj++; }



