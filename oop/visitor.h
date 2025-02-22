#pragma once

#include <stdlib.h>

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

class Shape3DVisitor;
// Base interface
class Shape3D {
public:
    virtual void collide(Shape3D* s2, Shape3D* s3, Shape3DVisitor& visitor) = 0;
    virtual void acceptAsSecond(Shape3D* s1, Shape3D* s3, Shape3DVisitor& visitor) = 0;
    virtual void acceptAsThird(Shape3D* s1, Shape3D* s2, Shape3DVisitor& visitor) = 0;
    virtual ~Shape3D() = default;
};

void collide3D(Shape3D& s1, Shape3D& s2, Shape3D& s3);


Element* get_element(int i);

Shape3D* get_shape3d(int i);
