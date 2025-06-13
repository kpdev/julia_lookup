class ElementA;
class ElementB;


class Element {
public:
    virtual ~Element() = default;
    virtual void visit(class Element* visitor) = 0;
    virtual void visit(class ElementA& visitor) = 0;
    virtual void visit(class ElementB& visitor) = 0;
};
    
class ElementA : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
};

class ElementB : public Element {
public:
    virtual void visit(class Element* visitor);
    virtual void visit(class ElementA& visitor);
    virtual void visit(class ElementB& visitor);
};

volatile int aa = 0;
volatile int ab = 0;
volatile int ba = 0;
volatile int bb = 0;

void ElementA::visit(class Element* visitor) {
    visitor->visit(*this);
}

void ElementA::visit(class ElementA& visitor) {
    aa++;
}

void ElementA::visit(class ElementB& visitor) { 
    ab++;
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

class ElementA ga;
class ElementB gb;