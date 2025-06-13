class ElementA;
class ElementB;
class ElementC;
class ElementD;


class Element {
public:
    virtual ~Element() = default;
    virtual void visit(class Element* visitor) = 0;
    virtual void visit(class ElementA& visitor) = 0;
    virtual void visit(class ElementB& visitor) = 0;
    virtual void visit(class ElementC& visitor) = 0;
    virtual void visit(class ElementD& visitor) = 0;
};
    
class ElementA : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
    virtual void visit(class ElementC& visitor);
    virtual void visit(class ElementD& visitor);
};

class ElementB : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
    virtual void visit(class ElementC& visitor);
    virtual void visit(class ElementD& visitor);
};

class ElementC : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
    virtual void visit(class ElementC& visitor);
    virtual void visit(class ElementD& visitor);
};

class ElementD : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
    virtual void visit(class ElementC& visitor);
    virtual void visit(class ElementD& visitor);
};

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

void ElementA::visit(class Element* visitor) {
    visitor->visit(*this);
}

void ElementA::visit(class ElementA& visitor) {
    aa++;
}

void ElementA::visit(class ElementB& visitor) { 
    ab++;
}

void ElementA::visit(class ElementC& visitor) { 
    ac++;
}

void ElementA::visit(class ElementD& visitor) { 
    ad++;
}



void ElementB::visit(class Element* visitor) { 
    visitor->visit(*this); 
}

void ElementB::visit(class ElementA& visitor) {
    ba++;
}

void ElementB::visit(class ElementB& visitor) {
    bb++;
}

void ElementB::visit(class ElementC& visitor) { 
    bc++;
}

void ElementB::visit(class ElementD& visitor) { 
    bd++;
}



void ElementC::visit(class Element* visitor) { 
    visitor->visit(*this); 
}

void ElementC::visit(class ElementA& visitor) {
    ca++;
}

void ElementC::visit(class ElementB& visitor) {
    cb++;
}

void ElementC::visit(class ElementC& visitor) { 
    cc++;
}

void ElementC::visit(class ElementD& visitor) { 
    cd++;
}



void ElementD::visit(class Element* visitor) { 
    visitor->visit(*this); 
}

void ElementD::visit(class ElementA& visitor) {
    da++;
}

void ElementD::visit(class ElementB& visitor) {
    db++;
}

void ElementD::visit(class ElementC& visitor) { 
    dc++;
}

void ElementD::visit(class ElementD& visitor) { 
    dd++;
}


class ElementA ga;
class ElementB gb;
class ElementC gc;
class ElementD gd;