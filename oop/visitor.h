#pragma once
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
