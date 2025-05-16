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


class Rectangle3D;
class Triangle3D;
class Circle3D;

class Shape3D {
public:
    // Invoked as s1
    virtual void collide(Shape3D* s2, Shape3D* s3) = 0;

    // Invoked as s2
    virtual void collide(Rectangle3D& s1, Shape3D* s3) = 0;
    virtual void collide(Triangle3D& s1, Shape3D* s3) = 0;
    virtual void collide(Circle3D& s1, Shape3D* s3) = 0;

    // Invoked as s3
    virtual void collide(Rectangle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Rectangle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Rectangle3D& s1, Circle3D& s2) = 0;

    virtual void collide(Triangle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Triangle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Triangle3D& s1, Circle3D& s2) = 0;

    virtual void collide(Circle3D& s1, Rectangle3D& s2) = 0;
    virtual void collide(Circle3D& s1, Triangle3D& s2) = 0;
    virtual void collide(Circle3D& s1, Circle3D& s2) = 0;

    virtual ~Shape3D() = default;
};


Element* get_element(int i);

Shape3D* get_shape3d(int i);

void visit_empty(Element* this_, class Element* visitor);
void collide_empty(Shape3D* this_, Shape3D* s2, Shape3D* s3);